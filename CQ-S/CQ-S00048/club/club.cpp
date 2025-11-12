#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e4+5;
int t,n,m,ans,a[N][4],cnt[4],id,sum,del[N];
struct node{int c1,c2,c3,p1,p2,p3;}ch[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n,m=n/2,ans=cnt[1]=cnt[2]=cnt[3]=id=sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3],del[i]=0;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ch[i].c1=a[i][1],ch[i].p1=1;
				if(a[i][2]>=a[i][3])ch[i].c2=a[i][2],ch[i].p2=2,ch[i].c3=a[i][3],ch[i].p3=3;
				else ch[i].c2=a[i][3],ch[i].p2=3,ch[i].c3=a[i][2],ch[i].p3=2;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ch[i].c1=a[i][2],ch[i].p1=2;
				if(a[i][1]>=a[i][3])ch[i].c2=a[i][1],ch[i].p2=1,ch[i].c3=a[i][3],ch[i].p3=3;
				else ch[i].c2=a[i][3],ch[i].p2=3,ch[i].c3=a[i][1],ch[i].p3=1;
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				ch[i].c1=a[i][3],ch[i].p1=3;
				if(a[i][1]>=a[i][2])ch[i].c2=a[i][1],ch[i].p2=1,ch[i].c3=a[i][2],ch[i].p3=2;
				else ch[i].c2=a[i][2],ch[i].p2=2,ch[i].c3=a[i][1],ch[i].p3=1;
			}ans+=ch[i].c1;
		}for(int i=1;i<=n;i++)cnt[ch[i].p1]++;
		for(int i=1;i<=3;i++)if(cnt[i]>m)id=i,sum=cnt[i]-m;
		int j=0;
		for(int i=1;i<=n;i++)if(ch[i].p1==id)del[++j]=ch[i].c1-ch[i].c2;
		sort(del+1,del+j+1);
		for(int i=1;i<=sum;i++)ans-=del[i];
		cout<<ans<<"\n";
	}return 0;
}
