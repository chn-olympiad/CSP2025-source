//#include<bits/stdc++.h>
//#define int long long
//#define N 100005
//using namespace std;
//int n,cn[N],to,exi[N];
//struct node{
//	int num,p,bh;
//}a[N<<2],b[N<<2];
//struct gap{
//	int gp1,gp2,bh;
//}gp[N];
//bool cp1(node a,node b){
//	return a.num>b.num;
//}
//bool cp2(int q,int w){
//	return a[exi[q]].num-a[(q-1)*n+to].num<b[exi[w]].num-a[(w-1)*n+to].num;
//}
//bool g1(gap a,gap b){
//	return a.gp1>b.gp1;
//}
//signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int t; cin>>t;
//	while(t--){
//		cin>>n;
//		int M=n>>1;
//		int ans=0;
//		cn[1]=cn[2]=cn[3]=0;
//		for(int i=1,j=0;i<=n;++i){
//			for(int k=1;k<=3;++k){
//				cin>>a[++j].num;
//				a[j].bh=i;
//				a[j].p=k;
//				b[j]=a[j];
//			}
//			sort(b+j-1,b+j+1,cp1);
//			gp[i].gp1=b[j].num-b[j-1].num;
//			gp[i].gp2=b[j-1].num-b[j-2].num;
//		}
//		sort(gp+1,gp+1+n,g1);
//		vector<int>l; l.clear();
//		for(int i=1;i<=n;++i){
//			int k=(i-1)*3,p1=b[k+1].p,p2=b[k+2].p;
//			if(cn[p1]<M){
//				++cn[p1];
//				ans+=b[k+1].num;
//				exi[i]=p1;
//			}
//			else{
//				if(cn[p2]!=M){
//					++cn[p2];
//					ans+=b[k+2].num;
//					exi[i]=p2;
//				}
//				else{
//					++cn[p1];
//					ans+=b[k+1].num;
//					exi[i]=p1;
//				}
//			}
//		}
//		to=0;
//		int out=0;
//		for(int i=1;i<=3;++i){
//			if(cn[i]<M)
//				to=i;
//			else if(cn[i]>M)
//				out=cn[i]-M;
//		}
//		if(!out){
//			cout<<ans<<"\n";
//			continue;
//		}
//		sort(l.begin(),l.end(),cp2);
//		for(int i=0;i<out;++i){
//			int no=l[i];
//			ans-=a[exi[no]].num-a[(no-1)*n+to].num;
//		}
//		cout<<ans<<"\n";
//	}
//	return 0;
//}拼尽全力无法战胜T1，但人还活着：| 
#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int n,cn[4];
bool vis[N];
struct node{
	int bh,p,num;
}s[N<<2];
bool cmp(node a,node b){
	return a.num>b.num;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		cin>>n;
		cn[1]=cn[2]=cn[3]=0;
		for(int i=1;i<=n;++i){
			cin>>s[i].num>>s[i+n].num>>s[i+n+n].num;
			s[i].p=1,s[i+n].p=2,s[i+n+n].p=3;
			s[i].bh=s[i+n].bh=s[i+n+n].bh=i;
			vis[i]=0;
		}
		sort(s+1,s+1+n*3,cmp);
		int cnt=0,M=n>>1,ans=0;
		for(int i=1;i<=n*3&&cnt<n;++i){
			int bh=s[i].bh,p=s[i].p;
			if(cn[p]>=M||vis[bh]) continue;
			++cn[p];
			vis[bh]=1;
			ans+=s[i].num;
			++cnt;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

















