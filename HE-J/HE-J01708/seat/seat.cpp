#include <bits/stdc++.h>
using namespace std;
int n,m,r;
int a[150];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(n*m);i++) scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+(n*m)+2,cmp);
	int rr=-1,cc=-1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			for(int j=2;j<=m;j+=2){
				if(i<=n*j){
					cout<<j<<" "<<n-(i-(j-1)*n)+1;
					return 0;
				}
			}
			for(int j=1;j<=m;j+=2){
				if(i<=n*j){
					cout<<j<<" "<<i-(j-1)*n;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
