#include<bits/stdc++.h>
using namespace std;
int d[2][2]={{0,1},{1,0}};
int ixor(int a,int b){
	int s=0,p=1;
	while(a!=0||b!=0){
		s+=d[a%2][b%2]*p;
		p*=2;
		a/=2;
		b/=2;
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	
	cin>>n>>k;
	int a[n+2],b[n+2];
	int t[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
		t[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(ixor(a[i],a[i+1])<=k&&a[i]<k){
			b[i+1]=b[i];
			int u=ixor(a[i],a[i+1]);
			for(int j=b[i];j<=i+1;j++){
			a[j]=u;
			}
			
		}
	}
	
	
	
	for(int i=1;i<=n;i++){
		if(a[i]==k)t[b[i]]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(t[i]!=0)ans++;
	}
	cout<<ans;
 return 0;
}
