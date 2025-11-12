#include<bits/stdc++.h>
using namespace std;
int ji[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<int> a;
	int n,m;
	cin >> n >> m;
	//输入+计数排序
	int r; //这里r是指小R的成绩  
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int temp;
			cin >> temp;
//			cout << temp << ' ';
			if(i == 1 && j == 1) r = temp;
			ji[temp]++;
		}
	}
//	cout << '\n';
	for(int i = 100;i >= 0;i--){
		while(ji[i] != 0){
			a.push_back(i);
			ji[i]--;
//			cout << a[a.size() - 1] << ' ';
		}
	}
//	cout << '\n';
	//找到小R的排名
	int t;
	for(int i = 0;i < a.size();i++){
		if(a[i] == r){
		    t = i + 1;//把t定义为小R的排名 
		    break;
		}
	}
//	cout << t << '\n';
	//判定+输出
	int nt,mt;
	if(((t - 1) / n) % 2 == 0){//t在奇数列的情况 
		mt = (t-1) / n + 1;
		nt = t - (mt-1)*n;
	} else {
		mt = (t-1) / n + 1;
		nt = (mt*n + 1) - t;
	}
	cout << mt << " " << nt;
	return 0;
}