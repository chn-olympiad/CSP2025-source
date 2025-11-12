#include<bits/stdc++.h>
using namespace std;
int a[100010][10];

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        vector<pair<int,int> >one;
        vector<pair<int,int> >two;
        vector<pair<int,int> >three;
        bool a1=1,a2=1,a3=1;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]!=0)
                a1=0;
            if(a[i][2]!=0)
                a2=0;
            if(a[i][3]!=0)
                a3=0;
        }
        if(a1&&a2){
            vector<int>t;
            for(int i=1;i<=n;i++){
                t.push_back(a[i][3]);
            }
            sort(t.begin(),t.end(),greater<int>());
            int ans=0;
            for(int i=0;i<n/2;i++){
                ans+=t[i];
            }
            cout<<ans<<'\n';
        }
        else if(a1&&a3){
            vector<int>t;
            for(int i=1;i<=n;i++){
                t.push_back(a[i][2]);
            }
            sort(t.begin(),t.end(),greater<int>());
            int ans=0;
            for(int i=0;i<n/2;i++){
                ans+=t[i];
            }
            cout<<ans<<'\n';
        }
        else if(a2&&a3){
            vector<int>t;
            for(int i=1;i<=n;i++){
                t.push_back(a[i][1]);
            }
            sort(t.begin(),t.end(),greater<int>());
            int ans=0;
            for(int i=0;i<n/2;i++){
                ans+=t[i];
            }
            cout<<ans<<'\n';
        }
        else if(n==2){
            int ans=a[1][1]+a[2][2];
            ans=max(ans,a[1][1]+a[2][3]);
            ans=max(ans,a[1][2]+a[2][1]);
            ans=max(ans,a[1][2]+a[2][3]);
            ans=max(ans,a[1][3]+a[2][1]);
            ans=max(ans,a[1][3]+a[2][2]);
            cout<<ans<<'\n';
        }
        else{
            int ans=0;
            vector<int>tmp;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                    tmp.push_back(a[i][j]);
                }
            }
            sort(tmp.begin(),tmp.end(),greater<int>());
            for(int i=0;i<n;i++){
                ans+=tmp[i];
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
