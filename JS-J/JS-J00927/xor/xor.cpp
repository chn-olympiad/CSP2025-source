#include<bits/stdc++.h>
using namespace std;

int n,k,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    vector<int>a(n),sum(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sum[0]=0;
    sum[1]=a[0];
    for(int i=1;i<n;i++){
        sum[i+1]=sum[i]^a[i];
    }
    //for(int i=0;i<=n;i++)cout<<sum[i]<<' ';
    set<pair<int,int> >ans;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            //cout<<i<<' '<<sum[i-1]<<"    "<<j<<' '<<sum[j]<<endl;
            if((sum[i-1]^sum[j])==k){
                ans.insert(make_pair(i,j));
                //cout<<i<<"    "<<j<<endl;
                break;
            }
        }
    }
    pair<int,int>last={-1,-1};
    for(auto c:ans){
        if(last.first!=-1){
            if(c.second<=last.second)ans.erase(last);
            else if(last.second>=c.first){
                if(last.second>=c.second)ans.erase(last);
                else ans.erase(c);
            }
            else last.first=c.first,last.second=c.second;
        }
        else last.first=c.first,last.second=c.second;
    }
    cnt=ans.size();
    cout<<cnt;
    return 0;
}
