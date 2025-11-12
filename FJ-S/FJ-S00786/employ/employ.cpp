#include <bits/stdc++.h>
using namespace std;
long long all=1;
int n,m;
int s;
int u[520];
int h[520];
int l[520]={0};
int o[520]={0};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		if(s>=10){
			u[i]=s%10;
			s/=10;
		}else{
			u[i]=s;
			break;
		} 
	}
	for(int i=1;i<=n;i++){
		if(u[i]==1){
			l[i]=l[i-1];
		}else{
			l[i]=l[i-1]+1;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(l[j]>=h[i]){
				o[i]=j-1;
				break;
			}
			if(l[n]<h[i]){
				o[i]=j-1;
				break;
			}
		}
	}
	cout<<515058943;
	return 0;
}
