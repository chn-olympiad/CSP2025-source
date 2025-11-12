#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int a[MAXN]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,f=0,v=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) cnt++;
		if(i!=1){
			if(a[i]!=a[i-1]) f=1;
			if(a[i]!=a[i-1]) v=1;
		}
		if(a[i]!=1) f=1;
		if(a[i]!=k) v=1;
	}
	if(v==0){
		cout<<n;
		return 0;
	}
	if(f==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n-1;j++){
			int f;
			if(j==1) f=a[j];
			else f=f^a[j];
			if(f==j){
				cnt++;
				break;
			}
		}
	}
	if(cnt>0) cout<<cnt-1;
	else cout<<cnt;
	return 0;
}