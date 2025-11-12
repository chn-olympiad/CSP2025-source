#include <bits/stdc++.h>
using namespace std;
long long n,q,num[200002];
string a[200002][2],t[200002][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1];
    for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
    for(int i=1;i<=q;i++){
        long long cnt1=0,cnt2=0;
        for(int j=0;j<t[i][0].size();j++){
            if(t[i][0][j]==t[i][1][j])cnt1++;
            else break;
        }
        for(int j=t[i][0].size()-1;j>=0;j--){
            if(t[i][0][j]==t[i][1][j])cnt2++;
            else break;
        }
        num[i]=cnt1*cnt2;
        //cout<<num[q]<<' ';
    }
    for(int k=1;k<=q;k++){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i][0].size();){
                if(j+t[k][0].size()>a[i][0].size()){
                    j++;
                    continue;
                }
                int f=1;
                for(int s=j;s<=j+t[k][0].size()-1;s++){
                    if(a[i][0][s]!=t[k][0][s-j]||a[i][1][s]!=t[k][1][s-j]){
                        j=s+1;f=0;
                        break;
                    }
                }
                if(f){
                    j+=t[k][0].size();
                    //cout<<num[k]<<k;
                    ans+=num[k];
                }
            }
            
        }cout<<ans<<endl;

    }
   // cout<<num[0]<<' '<<num[2];
    return 0;
}
