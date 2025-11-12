//GZ-S00491 贵阳市南明区双龙华麟学校 霍玥霓
//特A,m=1 
#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bool flag=1,f_=0;
	for(int i=0;i<n;i++){
		if(s[i]!=0) flag=0;
		else f_=1;
	}
	if(flag==1) cout<<1;
	if(f_==1 && m==1) cout<<n;
	return 0;
}
