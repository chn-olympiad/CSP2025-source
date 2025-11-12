#include<bits/stdc++.h>
using namespace std;
long long a[2005][2005],n,k,b[10005],cnt,sum=1;
struct A{
	long long l,r;
}c[4000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[i][i]=b[i];
		if(b[i]==k){
			cnt++;
			c[cnt].l=i;
			c[cnt].r=i;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			a[i][j]=a[i][j-1] xor b[j];
			if(a[i][j]==k){
				cnt++;
				c[cnt].l=i;
				c[cnt].r=j;
			}
		}
	}
	
	if(cnt==0){
		cout<<0;
		return 0;
		
	}
	long long ks=1e9;
	for(int i=1;i<=cnt;i++){
		if(c[i].r<ks){
			ks=c[i].r;
		}
	}
	bool gg=1;
	while(ks<n && gg==1){
		gg=0;
		long long mi=1e9;
		for(int i=1;i<=cnt;i++){
			if(c[i].r<mi && c[i].l>ks){
				gg=1;
				mi=c[i].r;
			}
		}
		if(gg==1){
			ks=mi;
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
