#include<bits/stdc++.h> 
using namespace std;
int m,n,b,c,d,e,g;
int a[101];
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	b=a[1];
	int t=0;
	for(int j=1;j<=m*n;j++){
		for(int i=1;i<=m*n;i++){
			if(a[i]<a[i+1]){
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	for(int i=1;i<=m*n;i++){
		if(a[i]==b){
			b=i;
			break;
		}
	}
	e=b/m+1;
	if(e%m==0)e=b/m;
	g=b%m;
	if(g%m==0)g=m; 
	cout<<e<<" "<<g;
	return 0;
}
