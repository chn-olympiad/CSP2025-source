#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
const int maxn=100005;
int t,n,a[maxn][4];
struct l{
    int l1,l2;
}chos[maxn];//最优和次优选择
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> d1,d2,d3;
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];

            if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))){
                chos[i].l1=1;
                if(a[i][2]>a[i][3]){
                    chos[i].l2=2;
                }
                else{
                    chos[i].l2=3;
                }
            }
            else if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))){
                chos[i].l1=2;
                if(a[i][1]>a[i][3]){
                    chos[i].l2=1;
                }
                else{
                    chos[i].l2=3;
                }
            }
            else{
                chos[i].l1=3;
                if(a[i][2]>a[i][1]){
                    chos[i].l2=2;
                }
                else{
                    chos[i].l2=1;
                }
            }
            if(chos[i].l1==1){
                d1.push(mp(a[i][1]-a[i][chos[i].l2],i));
                }
            if(chos[i].l1==2){
                d2.push(mp(a[i][2]-a[i][chos[i].l2],i));
            }
            if(chos[i].l1==3){
                d3.push(mp(a[i][3]-a[i][chos[i].l2],i));
            }
        }
            //最优次优判断，唐四了

        //for(int i=1;i<=n;i++){
            //cout<<chos[i].l1<<' '<<chos[i].l2<<"\n";
        //}
        while(d1.size()>n/2){
            pair<int,int> c1=d1.top();
            if(chos[c1.second].l2==2){
                d2.push(mp(-1,c1.second));
            }
            else{
                d3.push(mp(-1,c1.second));
            }
            d1.pop();
        }
        while(d2.size()>n/2){
            pair<int,int> c2=d2.top();
            if(chos[c2.second].l2==1){
                d1.push(mp(-1,c2.second));
            }
            else{
                d3.push(mp(-1,c2.second));
            }
            d2.pop();
        }
        while(d3.size()>n/2){
            pair<int,int> c3=d3.top();
            if(chos[c3.second].l2==2){
                d2.push(mp(-1,c3.second));
            }
            else{
                d1.push(mp(-1,c3.second));
            }
            d3.pop();
        }
        while(!d1.empty()){
            ans+=a[d1.top().second][1];
            //cout<<d1.top().first<<' ';
            d1.pop();
        }
        while(!d2.empty()){
            ans+=a[d2.top().second][2];
            //cout<<d2.top().first<<' ';
            d2.pop();
        }
        while(!d3.empty()){
            ans+=a[d3.top().second][3];
            //cout<<d3.top().first<<' ';
            d3.pop();
        }
        cout<<ans<<"\n";

    }
	return 0;
}
