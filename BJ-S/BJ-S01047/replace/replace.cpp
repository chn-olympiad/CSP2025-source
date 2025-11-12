#include<bits/stdc++.h>
using namespace std;
int n,q;
struct Node{
    string s1,s2;
    int s;
}a[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
        int x=a[i].s1.find('b'),y=a[i].s2.find('b');
        a[i].s=y-x;
        //cout<<y<<endl;
    }
    for(int i=1;i<=q;i++){
        string t1,t2;
        int ans=0;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()) cout<<0;
        else{
            int x=t1.find('b');
            int y=t2.find('b');
            int s1=y-x;
            for(int j=1;j<=n;j++){
                if(s1==a[j].s){
                    if(a[j].s1.find('b')<=x&&(a[j].s1.size()-a[j].s1.find('b')-1)<=(t1.size()-x-1)){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

