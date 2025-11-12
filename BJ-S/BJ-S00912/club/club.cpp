#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a,b,c;
        vector<long long>v1,v2,v3;
        long long ans=0; 
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            if(a>=b&&a>=c)v1.push_back(a-max(b,c)),ans+=a;
            else if(b>=a&&b>=c)v2.push_back(b-max(a,c)),ans+=b;
            else if(c>=a&&c>=b)v3.push_back(c-max(a,b)),ans+=c;
        }
        if(v1.size()>(n/2)){
            sort(v1.begin(),v1.end());
            for(int i=1;i<=v1.size()-(n/2);i++)
                ans-=v1[i-1];
        }
        if(v2.size()>(n/2)){
            sort(v2.begin(),v2.end());
            for(int i=1;i<=v2.size()-(n/2);i++)
                ans-=v2[i-1];
        }
        if(v3.size()>(n/2)){
            sort(v3.begin(),v3.end());
            for(int i=1;i<=v3.size()-(n/2);i++)
                ans-=v3[i-1];
        }
        cout<<ans<<"\n";
    }
    return 0;
}