#include<bits/stdc++.h>
using namespace std;
int n,m,c=1;
int t[20][20]={},f[200]={};
bool ans(int a,int b){
    return a>b;
}
int main(){
	freopen("numder.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	int a=f[1];
	sort(f+1,f+(m*n)+1,ans);
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			t[j][i]=f[c];
			if(f[c]==a){
				cout<<j<<" "<<i;
				return 0;
			}
			c++;
		}
		for(int j=n;j>=1;j--){
			int b=n;
			t[j][i+1]=f[c];			
			if(f[c]==a){
				cout<<j<<" "<<i+1;
				return 0;
			}
			c++;
		}
	}
	return 0;
}
