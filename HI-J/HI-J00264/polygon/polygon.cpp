#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	long long n,a[10001],b[1001],d,l[1001],e[1001],js,m=2;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
// ‰»Î
	for(int x=1;x<=n;x++){
		if(c[x]<c[x+1]){
			d=a[x];
			a[x]=a[x+1];
			a[x+1]=d;
		}
	}//√∞≈›
	for(int i=0;i<=n;i++){
		m++;
		for(int y=1;y<=m+1;y++){
			if(a[1]!=1){
				b[i]+=a[y];
				l[y]=a[y];
			}else{
				for(int z=2;z<=m+2;z++){
					b[i]+=a[z];
					l[y]=a[z];
				}
			}
		}
//º∆À„
		if(m>=3){
			for(int x=1;x<=m+1;x++){
				if(l[x]<l[x+1]){
					d=l[x];
					l[x]=l[x+1];
					l[x+1]=d;
				}
			}//√∞≈›
			if(b[i]>l[m+1]*2){
				js++;
			}
		}
//≈–∂®
	}
	cout<<js<<lend;
// ‰≥ˆ
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
