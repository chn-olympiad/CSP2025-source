#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> pai;
/*
Ren5Jie4Di4Ling5%
*/
const int N=1e5+50;
int a[N],b[N],c[N];
int t;
int n;
struct node{
    int mx,c;
};
bool cmp(node a,node b){
    return a.c<b.c;
}
vector<node>v;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        v.clear();
        cin>>n;
        int sum1=0,sum2=0,sum3=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            pai ss[10];
            ss[1]={a[i],1};
            ss[2]={b[i],2};
            ss[3]={c[i],3};
            sort(ss+1,ss+1+3);
            if(ss[3].second==1)++sum1;
            else if(ss[3].second==2)++sum2;
            else ++sum3;
            ans+=ss[3].first;
            v.push_back({ss[3].second,ss[3].first-ss[2].first});
        }
        sort(v.begin(),v.end(),cmp);
        int num=max({sum1,sum2,sum3});
        int mxi;
        if(sum1==num)mxi=1;
        else if(sum2==num)mxi=2;
        else mxi=3;
        //cout<<num<<"\n";
        if(num>n/2){
            int nd=num-n/2;
            for(int i=0;i<v.size();i++){
                //cout<<v[i].mx<<" "<<v[i].c<<"\n";
                if(!nd)break;
                if(v[i].mx==mxi){
                    ans-=v[i].c;
                    nd--;
                }
            }
        }
        cout<<ans<<"\n";
    }
    //cout<<123<<"\n";
}
