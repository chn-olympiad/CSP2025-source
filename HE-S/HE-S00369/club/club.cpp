#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int T,n,b[N],yg[5],vst[N];
long long ans;

struct node{
	int z,id;
}a[N][5],c[5][N];

bool cmp(int x,int y){
	return x>y;
}

bool cmp2(node x,node y){
	if(x.z==y.z) return x.id<y.id;
	return x.z>y.z; 
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>T;
	while(T--){
		cin>>n;
		
		for(int i=1;i<=3;i++) yg[i]=0;
		for(int i=1;i<=n;i++) vst[i]=i;
		ans=0;
		int gs=0;
		
		for(int i=1;i<=n;i++){
			cin>>a[i][1].z>>a[i][2].z>>a[i][3].z;
			a[i][1].id=1;
			a[i][2].id=2;
			a[i][3].id=3;
			if(a[i][2].z==a[i][3].z && a[i][2].z==0) gs++;
		}
		
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(a[1][i].id!=a[2][j].id) ans=max(ans,(long long)(a[1][i].z+a[2][j].z));
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		
		if(gs==n){
			for(int i=1;i<=n;i++) b[i]=a[i][1].z;
			
			sort(b+1,b+1+n,cmp);
			
			for(int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<"\n";
			
			continue;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
