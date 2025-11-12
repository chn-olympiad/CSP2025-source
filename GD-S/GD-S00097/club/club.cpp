#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
struct aaa{
	int a,b,c;
}v[N];
int n,a,b,c,ans,ab,ac,bc,abc,l[N],r[N];
int lr()
{
	priority_queue<int> q;
	int ret=0;
	for(int i=1;i<=n;i++){
		ret+=l[i];
		q.push(r[i]);
	}for(int i=1;i*2<=n;i++){
		ret+=q.top();
		q.pop();
	}return ret;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=a=b=c=0;
		for(int i=1;i<=n;i++){
			cin>>v[i].a>>v[i].b>>v[i].c;
		}for(int i=1;i<=n;i++){
		int x=max(v[i].b,v[i].c);
			ans+=max(v[i].a,x);
			if(v[i].a==x||(v[i].a<x&&v[i].b==v[i].c))continue;
			if(v[i].a>x){
				a++;
			}else{
				if(v[i].c>v[i].b)
					c++;
				else
					b++; 
			}
		}if(a*2<=n&&b*2<=n&&c*2<=n){
			cout<<ans<<"\n";
			continue; 
		}ans=0;
		for(int i=1;i<=n;i++){
			l[i]=v[i].a;
			r[i]=max(v[i].b,v[i].c);
			r[i]-=l[i];
		}ans=max(ans,lr());for(int i=1;i<=n;i++){
			l[i]=v[i].b;
			r[i]=max(v[i].a,v[i].c);
			r[i]-=l[i];
		}ans=max(ans,lr());for(int i=1;i<=n;i++){
			l[i]=v[i].c;
			r[i]=max(v[i].b,v[i].a);
			r[i]-=l[i];
		}ans=max(ans,lr());
		cout<<ans<<"\n";
		continue;
	}
}
/*ÏÈÌ°£¬a¶àÈÓb£¬b¶àÈÓc 
*/
