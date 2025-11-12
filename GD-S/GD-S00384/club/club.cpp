#include <bits/stdc++.h>
using namespace std;
long long n,a[10],b[10],c[10],d[10],e[10],f[10],g[10],h[10],k[10],l[10],t;
int cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		if(n>=2){
			for(int j=1;j<=3;j++){
				cin>>a[j];
			}
			for(int j=1;j<=3;j++){
				cin>>b[j];
			}
		}
		else if(n>=4){
			for(int j=1;j<=3;j++){
				cin>>c[j];
			}
			for(int j=1;j<=3;j++){
				cin>>d[j];
			}
		}
		else if(n>=10){
			for(int j=1;j<=3;j++){
				cin>>e[j];
			}
			for(int j=1;j<=3;j++){
				cin>>f[j];
			}
			for(int j=1;j<=3;j++){
				cin>>g[j];
			}
			for(int j=1;j<=3;j++){
				cin>>h[j];
			}
			for(int j=1;j<=3;j++){
				cin>>k[j];
			}
			for(int j=1;j<=3;j++){
				cin>>l[j];
			}
		}
			sort(a+1,a+4,cmp);
			sort(b+1,b+4,cmp);
			sort(c+1,c+4,cmp);
			sort(d+1,d+4,cmp);
			sort(e+1,e+4,cmp);
			sort(f+1,f+4,cmp);
			sort(g+1,g+4,cmp);
			sort(h+1,h+4,cmp);
			sort(k+1,k+4,cmp);
			sort(l+1,l+4,cmp);
			cout << a[1]+b[1]+c[1]+d[1]+e[1]+f[1]+g[1]+h[1]+k[1]+l[1];
	}
	return 0;
}
	

