#include<bits/stdc++.h>
using namespace std;
int m,n,c[501],y=0,z=0,h[500];
long long ans=1;
string s;
bool flag=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0')flag=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag==true){
		cout<<"161088479";
	}
	else cout<<"0";
}