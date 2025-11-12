#include<bits/stdc++.h>
using namespace std;
struct dd{
	int u;
	int y;
};
bool apa(dd a,dd b){
	return a.u>b.u;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	dd a[1001];
	a[0].y=1;
	for(int i=0;i<n*m;i++){
		cin>>a[i].u;
	}
	sort(a,a+(n*m),apa);
	int u=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[u].y){
				cout<<i<<" "<<j;return 0;
			}
			u++;
		}
	}
} 
