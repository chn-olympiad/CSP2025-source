#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=500005;
const int K=1050000;
int a[N];
int s[N];
vector<int >cnt[K];
vector<pair<int,int> >v;
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    cnt[k].push_back(0);
    bool flag=1;
    int g=0,b=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1){
            flag=0;
        }else if(a[i]==1){
            g++;
        }else if(a[i]==0){
            b++;
        }
        s[i]=s[i-1]^a[i];
        //cout<<s[i]<<" ";
        cnt[s[i]].push_back(i);

    }

    if(flag){
        if(k==1){
            cout<<g;
            return 0;
        }else{
            cout<<b;
            return 0;
        }
    }
    int idx=0;
    for(int i=0;i<=n;i++){
        int j=s[i]^k;
        if(!cnt[j].empty()){
            for(int c=0;c<cnt[j].size();c++){
                int mx,mn;
                if(cnt[j][c]>i){
                    mx=cnt[j][c];
                    mn=i;
                    v.push_back({mn+1,mx});
                }else if(cnt[j][c]<i){
                    mx=i;
                    mn=cnt[j][c];
                    v.push_back({mn+1,mx});
                }else{

                    mx=mn=i;
                }
                //idx++;
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    int ll=0;
    int ans=0;
    for(int i=0;i<v.size();i++){
        int l=v[i].first,r=v[i].second;
        //cout<<l<<" "<<r<<'\n';
        if(l>ll){
            ans++;
            ll=r;
        }
    }
    cout<<ans;
    return 0;
}
