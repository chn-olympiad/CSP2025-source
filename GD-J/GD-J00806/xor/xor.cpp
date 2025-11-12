#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,K=260;
int n,k,mx;
int a[N],f[N][K];
int ans;
void solve1(){
	for(int i=0;i<=n+2;i++)
		for(int j=0;j<=256;j++)
			f[i][j]=-1e9;
	f[1][a[1]]=0,f[1][0]=0;
	if(a[1]==k)f[1][0]++;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=255;j++){
			if(f[i-1][j]!=-1e9){
				f[i][j^a[i]]=max(f[i][j^a[i]],f[i-1][j]+((j^a[i])==k?1:0));
				ans=max(ans,f[i][j^a[i]]);
				if(j^a[i]==k)f[i][k]=-1e9;
			}
		}
		f[i][0]=max(f[i][0],ans);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=20;j++){
//			if(f[i][j]==-1e9)cout<<"e";
//			else cout<<f[i][j];
//			cout<<" ";
//		}
//		cout<<endl;
//	}
	printf("%d",ans);
}
//void solve2(){
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),mx=max(mx,a[i]);
	if(mx<=255)solve1();
//	else solve2();
	return 0;
}
//luogu uid:1485346
//rp+++++++++++++++++++++++++++++++++++++++++++++++++++
//密码神秘上善若水 
//www不会又要挂分了吧
//T3特殊性质C O(nk)都打不满
//9:56 打出了O(nk)的特殊性质解，大样例过 
//T4打完dfs+ai=1的性质，摆烂
//估分100+100+70+60=330，不挂就1=了
//sto lby&czz orz
