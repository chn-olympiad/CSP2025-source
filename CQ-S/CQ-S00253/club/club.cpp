#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define fr first
#define sc second
#define pq priority_queue
#define gr greater
#define mkp make_pair
using ll=long long;
using db=double;
using pii=pair<int,int>;

const int N=1e5+5;
int n;
array<pii,3>a[N];
pq<array<int,3>>q[3];

void solve(){
	cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j].fr;
            a[i][j].sc=j;
        }
        sort(all(a[i]),gr<pii>());
    }

	for(int i=0;i<3;i++)
		while(!q[i].empty()) q[i].pop();
    sort(a+1,a+n+1,gr<array<pii,3>>());
    int ans=0;
    for(int i=1;i<=n;i++){
        int tmp=a[i][0].sc;
        if(q[tmp].size()<n/2){
            ans+=a[i][0].fr;
            q[tmp].push({a[i][1].fr-a[i][0].fr,i,0});
        }
        else{
            int val=q[tmp].top()[0],pos=q[tmp].top()[1],cur=q[tmp].top()[2];
            q[tmp].pop();
            if(a[i][0].fr>-val){
                ans+=a[i][0].fr+val;
                q[tmp].push({a[i][1].fr-a[i][0].fr,i,0});
                q[a[pos][cur+1].sc].push({cur?(int)-1e9:a[pos][cur+2].fr-a[pos][cur+1].fr,pos,cur+1});
            }
            else{
                ans+=a[i][1].fr;
                q[tmp].push({a[pos][cur+1].fr-a[pos][cur].fr,pos,cur});
                q[a[i][1].sc].push({a[i][2].fr-a[i][1].fr,i,1});
            }
        }
    }

    cout<<ans<<'\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}
