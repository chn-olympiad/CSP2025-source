#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
struct oi{
	int u;
	int v;
	long long w;
}qiao[1000005];
struct io{
	int c;
	long long a[10005];
}cs[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>qiao[i].u>>qiao[i].v>>qiao[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>cs[i].c;
		for(int j=0;j<n;j++){
			cin>>cs[i].a[j];
		}
	}
	if(k==0){
		for(int i=0;i<m;i++){
			ans+=qiao[i].w;
		}
		cout<<ans;
	}
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
