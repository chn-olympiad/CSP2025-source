#include<bits/stdc++.h>
using namespace std;
int n,m;
int s1,s0; 
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0') s0++;
		else s1++;
	if(m>n-s0){
		cout<<0;
		return 0;
	}
	int l=1;
	for(int i=1;i<=n;i++){//12-14
		l=(l%998244353*l%998244353);
		l%=998244353;
	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}           
