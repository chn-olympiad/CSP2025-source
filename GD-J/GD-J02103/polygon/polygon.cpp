#include <bits/stdc++.h>
using namespace std;
long long result = 0;
int n,l,m_t;
int stick[5010] = {};
int temp[5010] = {};
int longest=0,total_long = 0;
void re_t(int xc){//初始化temp,结果是一个上升序列 
	for(int i = 0;i<=xc;i++){
		temp[i] = i;
	}
}

bool is_polygon(int t){//t是下标总数 
	longest = 0;
	total_long = 0;
	for(int i = 1;i<=t;i++){
		longest = max(longest,stick[temp[i]]);
		total_long+=stick[temp[i]];
	}
	if(total_long>2*longest) return true;
	return false;
}

int moveable_t(int xc){
	if(temp[xc] != n) return xc;
	for(int i = xc-1;i>=1;i--){
		if(temp[i] != temp[i+1]-1) return i;
	}
	return 114514;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> stick[i];
	}
	
	for(int i = 3;i<=n;i++){//i:取木棍数,也是下标总数 
		re_t(i);
		if(is_polygon(i)){
			result++;
			//test(i);
		}
		while(moveable_t(i) != 114514){//根据下标，进行遍历，重点为下标的改变，执行到遍历结束 
			m_t = moveable_t(i);
			temp[m_t]++;
			if(m_t!=i){//moveable_t(i)以右的下标都要挪到与之相邻的位置 
				for(int j = m_t+1;j<=i;j++){
					temp[j] = temp[j-1]+1;
				}
			}
			if(is_polygon(i)){
				result++;
			}
			
		}
	}
	cout << result%998244353;
	return 0;
}

