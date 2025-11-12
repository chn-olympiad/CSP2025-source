#include<bits/stdc++.h> 
using namespace std;
int n,m,k,a,b,c;long long x=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);x+=a+b+c;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a);x+=a;
		}
	}
	cout<<x/m/k;
	return 0;
}
