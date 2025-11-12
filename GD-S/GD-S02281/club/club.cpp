#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long
struct stu{
	int a,b,c;
}k[N];
bool cmp1(stu x,stu y){
	return x.a>y.a;
}
bool cmp2(stu x,stu y){
	return abs(x.a-x.b)>abs(y.a-y.b);
}
int t,n,v[N],ans=0,maxx=-1;
void dfs(int dep,int a,int b,int c){
	if(dep==n+1){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a<n/2&&v[i]==0){
			ans+=k[i].a;
			v[i]=1;
			a++;
		}
		else if(b<n/2&&v[i]==0){
			ans+=k[i].b;
			v[i]=1;
			b++;
		}
		else if(c<n/2&&v[i]==0){
			ans+=k[i].c;
			v[i]=1;
			c++;
		}
		dfs(dep+1,a,b,c);
	}
}
signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int ans=0,wb=0,wc=0,va=0,vb=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>k[i].a>>k[i].b>>k[i].c;
			wb+=k[i].b,wc+=k[i].c;
		}
		if(wb==0&&wc==0){
			sort(k+1,k+1+n,cmp1);
			for(int i=1;i<=n/2;i++) ans+=k[i].a;
		}
		else if(wb!=0&&wc==0){
			sort(k+1,k+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(k[i].a>=k[i].b){
				if(va<n/2){
					ans+=k[i].a;
					va++;
				}
				else ans+=k[i].b,vb++;
				}
				else if(k[i].a<k[i].b){
				if(vb<n/2){
					ans+=k[i].b;
					vb++;
				}
				else ans+=k[i].a,va++;
				}
			}
		}
		else {
			dfs(1,0,0,0);
			ans=maxx;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
