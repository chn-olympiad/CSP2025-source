#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5*100000+5;
int n,K,a[maxn],num[maxn],ans,cnt;
bool vis[maxn];
struct node{int l,r;}bj[maxn];
bool cmp(node n1,node n2){return n1.r<n2.r;}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) num[i]=a[i];
		else num[i]=num[i-1]^a[i];
	}
	if(K==1){
		for(int i=1;i<=n;i++)
		if(a[i]==K) ans++;
		cout<<ans<<endl;
	}else if(K==0){
		for(int i=1;i<=n;i++)
		if(a[i]==K) ans++;
		else if(a[i]==a[i-1]) ans++;
		cout<<ans<<endl;
	}else if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=1,k=i;k<=n;j++,k++){
				if(i==1 && a[j]==K){
					ans++; vis[j]=1;
				}else{
					int flag=0,cnt1;
					for(int i=j;i<=k;i++)
						if(vis[i]){flag=1; cnt1=i; break;}
					if(flag==1){j=cnt1,k=cnt1+i-1; continue;}
					if((num[j-1]^num[k])==K) bj[++cnt].l=j,bj[cnt].r=k;
				}
			}
		}
		sort(bj+1,bj+1+cnt,cmp);
		int lr=bj[1].r;
		for(int i=2;i<=cnt;i++){if(bj[i].l>lr){lr=bj[i].r; ans++;}}
		cout<<ans+1<<endl;
	}//分段程序
	else{
		for(int i=1;i<=n;i++)
		if(a[i]==K) ans++;
		else if(a[i]==a[i-1]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}