#include<iostream>
#include<string>
using namespace std;
const int N=200005;
int n,q,l[N],r[N],a[N];
string s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        int x1,x2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b')x1=j;
            if(s2[j]=='b')x2=j;
        }
        l[i]=min(x1,x2);
        a[i]=x2-x1;
        r[i]=s1.size()-max(x1,x2)-1;
    }
    while(q--){
        int ans=0;
        cin>>s1>>s2;
        int x1,x2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b')x1=j;
            if(s2[j]=='b')x2=j;
        }
        // cout<<x1<<' '<<x2<<endl;
        int ll=min(x1,x2);
        int rr=s1.size()-max(x1,x2)-1;
        // cout<<ll<<" "<<rr<<" "<<x2-x1<<endl;
        for(int i=1;i<=n;i++){
            if(x2-x1==a[i]&&l[i]>=ll&&r[i]<=rr)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}