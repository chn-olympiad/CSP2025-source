#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum=0,nc[1000],nx[1000],cnt=0;
char st[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	sum=n;
	for(int i=1;i<=n;i++){
	cin>>st[i];
	}
	for(int i=1;i<=n;i++){
	cin>>nx[i]; 
	} 
	for(int i=1;i<=n;i++){
		if(st[i]=='0'){
			for(int j=1;j<=n;j++){
				nx[j]-=1;
			}
		}
		if(nx[i]<=0){
		sum--;
		}
		if(sum<=m){
			cnt++;
		}
	}
	cout<<((n-1)*n+n)/2-cnt;
	return 0;
} 
