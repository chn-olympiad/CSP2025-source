#include<bits/stdc++.h>
using namespace std;
int a[1000],h[105],l[105];
int main()
{
	int n,m,b,o=1,p=1,k=1,ws=0;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)k=i;
		b=i;
	}
	for(int i=0;i<b;i++){
		for(int j=2;j<=b;j++){
			if(a[j]>a[j-1]){
				int g;
				g=a[j];
				a[j]=a[j-1];
				a[j-1]=g;
				if(j-1==k)k=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(m%2!=0){
			for(int j=1;j<=n;j++){
				ws++;
				if(ws==k){
					h[o]=j;
					l[p]=i;
					o++;
					p++;
				}
			}
		}
		else{
			for(int e=n;e>=1;e--){
				ws++;
				if(ws==k){
					h[o]=e;
					l[p]=i;
					o++;
					p++;
				}
			}
		}
	}
	cout<<l[1]<<' '<<h[1];
	return 0;
}
