#include<bits/stdc++.h>
using namespace std;
int s[5009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0,zd=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]>zd)zd=s[i];
		cnt+=s[i];
	}
	if(cnt>zd*2)cout<<1;
	else cout<<0;
}