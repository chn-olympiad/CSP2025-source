#include<bits/stdc++h>
using namespace std;
int n,m,k;
int a[10001],b[10001],w[10001],c[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>w[i];
		c[i]=abs(a[i],b[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(c[j]>c[j+1]){
				swap(c[j],c[j+1]);
				swap(w[j],w[j+1]);
			}
			if(c[j]==c[j+1]&&w[j]>w[j+1]){
				swap(c[j],c[j+1]);
				swap(w[j],w[j+1]);
			}
		}
	}
	int ans;
	int q=1;
	for(int i=1;i<=n;i++){
		if(c[i]==q){
			ans+=w[i];
			q++;
		}
		if(q==n-1){
			break;
		}
	}
	cout<<ans;
	return 0;
}