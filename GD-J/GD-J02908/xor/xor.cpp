#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[1001]={0},d[1001]={0},n,k,l[100001],r[100001],x=1,mx,s=0,kk=1;
	cin>>n>>k>>a[1];
	d[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		d[i]=d[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
		if(i==j){
			if(a[i]==k){
				r[x]=i;
				l[x]=j;
				x++;
			}
		}
		else{
			if((d[i]^d[j-1])==k){
				r[x]=i;
				l[x]=j;
				x++;
			}
		}
		}
	}
	for(int i=1;i<=n;i++){
		mx=100971;
		for(int j=1;j<=x-1;j++){
			if(r[j]==i&&mx>l[j]){
				mx=r[j];
			}
		}if(mx!=100971){
		    s++;
		    i=mx+1;
		}
	}cout<<s;
}
