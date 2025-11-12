#include<bits/stdc++.h>
using namespace std;

struct node{
    string s1,s2;
}a[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
    while(m--){
        int ans=0;
        string qs1,qs2;
        cin>>qs1>>qs2;
            string ts=qs1;
        if(qs1.size()!=qs2.size()){
            cout<<0;
            continue;
        }
        for(int j=1;j<=n;j++)

        if(qs1.find(a[j].s1)<=n){

            for(int i=qs1.find(a[j].s1);i<=qs1.find(a[j].s1)+a[j].s1.size();i++){
                ts[i]=a[j].s2[i];
            }
        if(ts.find(qs2)==0) ans++;
        }


        cout<<ans<<endl;
    }
    return 0;

}
