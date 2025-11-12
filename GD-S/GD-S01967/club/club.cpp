#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll,pair<ll,ll> > >pr;
const int N = 1000005;
ll T;
ll n,d[N],s[N],ans;
priority_queue<pr>q;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--){
        while(!q.empty())q.pop();
        memset(d,0,sizeof(d));
        memset(s,0,sizeof(s));
        ans=0;
        cin>>n;
        for(int i=1,x[5];i<=n;++i){
        	for(int j=1;j<=3;++j){
	            cin>>x[j];
			}
            q.push(make_pair(x[1]-2*x[2]-2*x[3],
                make_pair(i,make_pair(1,x[1]))));
            q.push(make_pair(x[2]-2*x[1]-2*x[3],
                make_pair(i,make_pair(2,x[2]))));
            q.push(make_pair(x[3]-2*x[2]-2*x[1],
                make_pair(i,make_pair(3,x[3]))));
		}
        while(!q.empty()){
            pr tmp=q.top();
            q.pop();
            ll x=tmp.second.second.second,i=tmp.second.first,
                j=tmp.second.second.first;
            if(d[i])continue;
            if(s[j]>=n/2)continue;
            d[i]=1;
            ++s[j];
            ans+=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
