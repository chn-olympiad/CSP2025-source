//GZ-S00459 贵阳市第一中学 陈加涵 
#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[501];
bool check(string s){
	int len=s.length();
	for(int i=1;i<=len;i++){
		if(s[i]=='0') return false;
	}
	return true;
}
void solve1(){
	long long sum=1;
	int cnt=n;
	for(int i=1;i<=n;i++){
		if(c[i]==0) cnt--;
	}
	for(int i=1;i<=cnt;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(check(s)){//所有人都能做出 
		solve1();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
