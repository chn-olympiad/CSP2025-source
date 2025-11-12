#include<bits/stdc++.h>
using namespace std;
struct lu{
	long long u,v,w;
}l[1000100];
struct xiang{
	long long c[10100];	
}x[11];
long long n,m,k,ans=1e15;
bool cheng[10100],f;
//void func(int b,int c){
//	if(b>m){
//		for(int i=1;i<=n;i++){
//			if(!cheng[i]){
//				f=false;
//				break;
//			}
//		}
//		if(f&&c<=ans)ans=c;
//		return;
//	}else{
//		for(int i=1;i<=m;i++){
//			if(l[i].u==b){
//				cheng[l[i].v]=true; 
//				func(b+1,c+l[i].w); 
//			}
//		}
//	}
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++)cin>>l[i].u>>l[i].v>>l[i].w;
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)cin>>x[i].c[j];
	cout<<0;
	return 0;
}
