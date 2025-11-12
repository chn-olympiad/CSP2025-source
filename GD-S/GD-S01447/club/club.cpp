#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int a,id1,id2;//1 ²¿ÃÅ £¬2 ÐòºÅ 
}a1[N],a2[N],a3[N];//1max,2mid,3min
bool cmp(node x,node y){
	return x.a>y.a;
}
int f[N],num[4],a[4][N];
int b[4][N];
int n;
int dfs(int k,int l){
	if(k==n) return a[l][k];
	int op=0;
	for(int i=1;i<=3;i++){
		op=max(op,dfs(k+1,i)+a[l][k]);
	}
	return op;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(num,0,sizeof(num));
		
		cin>>n;
		if(n==2){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[j][i];
				}
				
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=n;k++){
						for(int l=1;l<=3;l++){
							if(j!=l&&i!=k){
								ans=max(ans,a[j][i]+a[l][k]);
							}
						} 
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
//		if(n<=200){
//			int ans=0;
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=3;j++){
//					cin>>a[j][i];
//				}
//				
//			}
//			for(int i=1;i<=3;i++){
//				ans=max(dfs(1,i));
//			}
//			cout<<ans;
//		}
		int fff=0;
		for(int i=1;i<=n;i++){
			node x,y,z;
			cin>>x.a>>y.a>>z.a;
			b[1][i]=x.a;b[2][i]=y.a;b[3][i]=z.a;
			if(z.a!=0||y.a!=0) fff=1;
			x.id1=1;y.id1=2;z.id1=3;
			x.id2=i;y.id2=i;z.id2=i;
			node p[3]={x,y,z};
			sort(p,p+3,cmp);
			a1[i]=p[0];a2[i]=p[1];a3[i]=p[2];
		}
		if(fff==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=b[1][i];
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(a1+1,a1+1+n,cmp);
		sort(a2+1,a2+1+n,cmp);
		sort(a3+1,a3+1+n,cmp);
		
//		printf("\n---------\n");
//		for(int k=1;k<=3;k++){
//			for(int i=1;i<=n;i++){
//				cout<<a[k][i].a<<" ";
//			}
//			printf("\n");
//			for(int i=1;i<=n;i++){
//				cout<<a[k][i].id1<<" "; 
//			} 
//			printf("\n");
//			for(int i=1;i<=n;i++){
//				cout<<a[k][i].id2<<" ";
//			}
//			printf("\n\n");
//		}
//		printf("-------------\n");
		int ans=0;
		
		for(int i=1;i<=n;i++){
			int ff=0;
			if(f[a1[i].id2]==0){
				if(num[a1[i].id1]<(n/2)){
						f[a1[i].id2]=1;
						num[a1[i].id1]++;
						ans+=a1[i].a;
//						break; 
						ff=1;
				}
			}
			if(ff==1) continue;
			if(f[a2[i].id2]==0){
				if(num[a2[i].id1]<(n/2)){
						f[a2[i].id2]=1;
						num[a2[i].id1]++;
						ans+=a2[i].a;
						ff=1;
//						break; 
				}
			}
			if(ff==1) continue;
			if(f[a3[i].id2]==0){
				if(num[a3[i].id1]<(n/2)){
						f[a3[i].id2]=1;
						num[a3[i].id1]++;
						ans+=a3[i].a;
//						break; 
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

