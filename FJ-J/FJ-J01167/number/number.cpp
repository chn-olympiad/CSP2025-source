#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+5;

int cnt,a[N]; // cnt:当前存储位置的下标

bool cmp(int x,int y){ // 从大到小排序
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		char c=s[i];
		if(c>='0' && c<='9'){ // 当前位是数字
			a[++cnt]=c-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	bool flag=false; // 用于去除前导0
	for(int i=1;i<=cnt;i++){
		if(a[i]>=1 && a[i]<=9){
			flag=true;
			cout<<a[i];
		}else if(flag){ // 若当前位为0, 当且仅当此前出现过非0数才输出
			cout<<a[i];
		}
	}
	return 0;
}
