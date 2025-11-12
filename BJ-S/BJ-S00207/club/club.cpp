#include<bits/stdc++.h>

using namespace std;

struct node{
    int a[5];
};
int T;
int ans=0;
int n;
node lst[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        int t[5]={0,0,0,0,0};
        int cnt[5]={0,0,0,0,0};
        vector<int> v[5];
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>lst[i].a[1]>>lst[i].a[2]>>lst[i].a[3];
        }

        for(int i=1;i<=n;i++){
            int maxi=max(lst[i].a[1],max(lst[i].a[2],lst[i].a[3]));
            int p;
            if(lst[i].a[1]==maxi){
                p=1;
            }
            else if(lst[i].a[2]==maxi){
                p=2;
            }
            else{
                p=3;
            }

            v[p].push_back(i);
            ans+=lst[i].a[p];
        }

        for(int j=1;j<=3;j++){
            if(v[j].size()>n/2){
                vector<int> t;
                for(int i=0;i<v[j].size();i++){
                    int x=lst[v[j][i]].a[j];
                    lst[v[j][i]].a[j]=0;
                    int maxi=max(lst[v[j][i]].a[1],max(lst[v[j][i]].a[2],lst[v[j][i]].a[3]));
                    t.push_back(x-maxi);
                }
                sort(t.begin(),t.end());
                for(int i=0;i<v[j].size()-n/2;i++){
                    ans-=t[i];
                }

            }
        }

        cout<<ans<<'\n';
    }

    return 0;
}
