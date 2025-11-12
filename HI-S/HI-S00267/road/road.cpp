#include <bits/stdc++.h>
using namespace std;
int a[1000015],a2[1000006];
int n,m,k,b,c,d,e,f,g,h,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=1000005;i++) a[i]=INT_MAX;
	for(int i=1;i<=m;i++){
		cin>>e>>f>>g;
		if(e>f){
			h=f;
			f=e;
			e=h;
		}
		a[e]=min(g,a[e]);
	}
	for(int i=1;i<=k;i++){
		cin>>b;
		for(int j=1;j<=m;j++){
			cin>>a2[j];
			for(int r=1;r<j;r++){
				a[r]=min(a[r],b+a2[j]+a2[r]);
			}
		}
	}
	for(int i=1;i<n;i++){
		sum+=a[i];
	}
	cout<<sum;
	return 0;
}
