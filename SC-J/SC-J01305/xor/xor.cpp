#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],ans,sum[N];
struct node{
	int i,w;
}z[N];

bool cmp(node x,node y){
	return x.w<y.w;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		z[i].i=i;
	}
	int f=0; 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				z[i].w=j;
				f=1;
				break;
			}
		}
		if(f==0){
			z[i].w=n+1;
		}
		f=0;
	}
	sort(z+1,z+1+n,cmp);
	int lst=0;
	for(int i=1;i<=n;i++){
		if(z[i].w==n+1)
			break;
		if(z[i].i<=lst){
			continue;
		}
		ans++;
		lst=z[i].w;
	}
	cout<<ans;
	return 0;
}