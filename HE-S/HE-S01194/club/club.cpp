#include<bits/stdc++.h>
using namespace std;
const int N=1e5+86;
struct node{
	int num,i;
}a[N],b[N],c[N];
bool cmp(node a,node b){
	if(a.num==b.num) return a.i<b.i;
	else return a.num>b.num;
}
int vis[N];
int ans=0,res;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin>>t;
	while(t--){
		ans=0;
		int cta=0,ctb=0,ctc=0;
		int n; cin>>n;
		for(int i=1;i<=n;++i){
			vis[i]=0;
		}
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i].num,&b[i].num,&c[i].num);
			a[i].i=i; b[i].i=i; c[i].i=i;
		}
//		if(n<=30){
//			dfs(n,1,0,0,0);
//			cout<<res<<'\n'; continue;
//		}
		for(int i=1;i<=n/2;++i){
			ans+=a[i].num;
		}
		cout<<ans<<'\n';
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
//		for(int i=1,j=1,k=1,ni=2,nj=2,nk=2;cnt<n;){
////			int ac=a[i].num,bc=b[j].num,cc=c[k].num;
////			if()
////			if(vis[a[i].i]){
////					cta++; i++;
////				}
////			if(vis[b[j].i]){
////					ctb++; j++;
////				} 
////			if(vis[c[k].i]){
////					ctc++; k++;
////				} 
////			int ac,bc,cc;
////			do{
////				ac=a[i].num-a[i+1].num;
////			}while(vis[i]||vis[i+1]);
////			do{
////				bc=b[j].num-b[j+1].num;
////			}while(vis[j]||vis[j+1]);
////			do{
////				cc=c[k].num-c[k+1].num;
////			}while(vis[k]||vis[k+1]);
////			if(i-cta==n/2||j-ctb==n/2||k-ctc==n/2){
//			for(int z=i;z<=n+1;z++){
//				if(vis[a[z].i]){
//					 cta++; i++;	 
//				}else break;
//			}
//			for(int z=j;z<=n+1;z++){
//				if(vis[b[z].i]){
//					ctb++; j++; 
//				} else break;
//			}
//			for(int z=k;z<=n+1;z++){
//				if(vis[c[z].i]){
//					ctc++; k++;
//				} else break;
//			}
//			for(int z=ni;z<=n+1;z++){
//				if(vis[a[z].i]){
//					ni++; 
//				} else break;
//			}
//			for(int z=nj;z<=n+1;z++){
//				if(vis[b[z].i]){
//					nj++; 
//				} else break;
//			}
//			for(int z=nk;z<=n+1;z++){
//				if(vis[c[z].i]){
//					nk++;
//				} else break;
//			}
//			int	ac=max(a[i].num+b[nj].num,a[i].num+c[nk].num);
//			int	bc=max(b[j].num+a[ni].num,b[j].num+c[nk].num);
//			int	cc=max(c[k].num+a[ni].num,c[k].num+b[nj].num);
////			} 
//			if(i-cta==n/2+1) ac=-1;
//			if(j-ctb==n/2+1) bc=-1;
//			if(k-ctc==n/2+1) cc=-1;
//			if(ac>=bc&&ac>=cc){
//				vis[a[i].i]=1; ans+=a[i].num; cnt++; 
//				
//			}else if(bc>=ac&&bc>=cc){
//				vis[b[j].i]=1; ans+=b[j].num; cnt++;
//				
//			}else{
//				vis[c[k].i]=1; ans+=c[k].num; cnt++;
//				
//			}
//		}
//		cout<<ans<<'\n';
	}
	return 0;
}
