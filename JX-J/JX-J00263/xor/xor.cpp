#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k;
int a[N];
int xr[N];
vector<pair<int,int> > qj;
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.second==y.second) return x.first>y.first;
    return x.second<y.second;
}
int r;
long long ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>k;
//
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xr[i]=xr[i-1]^a[i];
    }
    //cout<<'\n';

    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if((xr[i]^xr[j-1])==k){
                qj.push_back(make_pair(j,i));
            }
        }

    }

    sort(qj.begin(),qj.end(),cmp);

    for(int i=0;i<qj.size();i++){
        if(qj[i].first>r){
            r=qj[i].second;
            ans++;
        }
    }

    cout<<ans;
	return 0;
}

