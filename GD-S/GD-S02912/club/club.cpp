#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005],b[100005],c[100005],x[5][100005];
bool cmp(int x,int y){
	int numx=min(a[x]-b[x],a[x]-c[x]),numy=min(a[y]-b[y],a[y]-c[y]);
	return numx<numy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		long long ans=0;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				x[1][++x[1][0]]=i;
				ans+=a[i];
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				x[2][++x[2][0]]=i;
				ans+=b[i]; 
			}else{
				x[3][++x[3][0]]=i;
				ans+=c[i];
			}
		}
		int m=n/2;
		if(x[1][0]<=m&&x[2][0]<=m&&x[3][0]<=m){
			cout<<ans<<endl;
			continue;
		}
		if(x[2][0]>m){
			swap(x[1],x[2]);
			swap(a,b);
		}else if(x[3][0]>m){
			swap(x[1],x[3]);
			swap(a,c);
		}
		cout<<n<<" "<<ans<<" "<<x[1][0]<<" "<<x[2][0]<<" "<<x[3][0]<<" ";
		sort(x[1]+1,x[1]+x[1][0]+1,cmp);
		for(int i=1;i<=x[1][0]-m;i++){
			int cur=x[1][i];
			ans-=min(a[cur]-b[cur],a[cur]-c[cur]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
