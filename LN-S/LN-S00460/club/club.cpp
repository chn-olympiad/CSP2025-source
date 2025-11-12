#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
    int x,y,z,o,m,n,sum;
};
bool cmp(Node m,Node n){
    return m.sum>n.sum;
}
vector<Node>v;// index begins from 0;
void GoWork(){
    v.clear();
    int n,e=0,f=0,g=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int o,m,n,l,x,y,z;
        cin>>o>>m>>n;
        x=o,y=m,z=n;
        int maxn=max(o,max(m,n));
        o=maxn-o,m=maxn-m,n=maxn-n;
        l=o+m+n;
        v.push_back({x,y,z,o,m,n,l});
    }
    sort (v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        Node a=v[i];
        int z=(a.o==0)?(1):((a.m==0)?(2):(3));
        if(z==1){
            if(e<n/2)ans+=a.x,e++;
            else if(f<n/2&&g<=n/2){
                if(a.y>a.z)f++,ans+=a.y;
                else g++,ans+=a.z;
            }
            else if (f<n/2)ans+=a.y,f++;
            else ans+=a.z,g++;
        } else if(z==2){
            if(f<n/2)ans+=a.y,f++;
            else if(g<n/2&&e<n/2){
                if(a.x>a.z)e++,ans+=a.x;
                else g++,ans+=a.z;
            }
            else if (e<n/2)ans+=a.x,e++;
            else ans+=a.z,g++;
        } else if(z==3){
            if(g<n/2)ans+=a.z,g++;
            else if(f<n/2&&e<n/2){
                if(a.y>a.x)f++,ans+=a.y;
                else e++,ans+=a.x;
            }
            else if (f<n/2)ans+=a.y,f++;
            else ans+=a.x,e++;
        }
    }
    cout<<ans<<endl;
}


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)GoWork();
    return 0;
}
