#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
bool cmp(pii a,pii b){
    if(a.second!=b.second)  return a.second<b.second;
    return a.first<b.first;
}
int n,m;
int a[500005];
int sum[500005];
vector<pii> vec;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        int r=i;
        while(r<=n && (sum[r]^sum[i-1])!=m)  r++;
        if(r>n)  continue;
        vec.push_back(make_pair(i,r));
    }
    sort(vec.begin(),vec.end(),cmp);
    int ans=0,last=0;
    for(int i=0;i<(int)vec.size();i++){
        if(last<vec[i].first)  last=vec[i].second,ans++;
    }
    cout<<ans<<endl;
    return 0;
}
/*
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
bool cmp(pii a,pii b){
    if(a.second!=b.second)  return a.second<b.second;
    return a.first<b.first;
}
int n,m;
int a[500005];
pii sum[500005];
vector<pii> vec;
int main(){
    freopen("xor6.in","r",stdin);
    freopen("xor6.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i].first=(sum[i-1].first^a[i]);
        sum[i].second=i;
    }
    sort(sum,sum+n+1);
   // for(int i=0;i<=n;i++)  cout<<sum[i].first<<" ";cout<<endl;
   // for(int i=0;i<=n;i++)  cout<<sum[i].second<<" ";cout<<endl;
    for(int i=0;i<=n;i++){
       // cout<<"i = "<<i<<endl;
        int it1=lower_bound(sum,sum+n+1,make_pair(m^sum[i].first,0))-sum;
        int it2=upper_bound(sum,sum+n+1,make_pair(m^sum[i].first,INT_MAX))-sum-1;
        if(it1==n+1 || it2==0)  continue;
        if(sum[it1].first!=m^sum[i].first || sum[it2].first!=m^sum[i].first)  continue;
       // cout<<"it1 = "<<it1<<" it2 = "<<it2<<endl;
        if(sum[i].second<sum[it1].second){
            vec.push_back(make_pair(sum[i].second+1,sum[it1].second));
          //  cout<<"1: "<<sum[i].second+1<<" "<<sum[it1].second<<endl;
        }else if(sum[i].second>sum[it2].second){
            vec.push_back(make_pair(sum[it2].second+1,sum[i].second));
          //  cout<<it2<<" "<<i<<endl;
          //  cout<<"2: "<<sum[it2].second+1<<" "<<sum[i].second<<endl;
        }else{
            if(i+1<=it2){
                vec.push_back(make_pair(sum[i].second+1,sum[i+1].second));
            //    cout<<"31: "<<sum[i].second+1<<" "<<sum[i+1].second<<endl;
            }
            if(i-1>=it1){
                vec.push_back(make_pair(sum[i-1].second+1,sum[i].second));
              //  cout<<"32: "<<sum[i].second+1<<" "<<sum[i-1].second<<endl;
            }
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    int ans=0,last=-1;
   // cout<<endl;
    for(int i=0;i<(int)vec.size();i++){
          //  cout<<vec[i].first<<" "<<vec[i].second<<endl;
        if(last<vec[i].first)  last=vec[i].second,ans++;
    }
    cout<<ans<<endl;
    return 0;
}

*/
