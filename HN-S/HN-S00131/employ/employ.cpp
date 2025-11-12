#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char s[n+1];
	int c[n+1];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int sl1=0,sl0=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1') sl1++;
		else sl0++;
	}
	cout<<sl1;
}
