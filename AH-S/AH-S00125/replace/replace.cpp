#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
    int m1,m2,l;
}a[210000];
string a1,a2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int q=1;q<=n;q++){
        cin>>a1>>a2;
        for(int w=0;w<a1.size();w++){
            if(a1[w]=='b')a[q].m1=w;
            if(a2[w]=='b')a[q].m2=w;
        }
        a[q].l=a1.size();
    }
    for(int i=1;i<=q;i++){
        cin>>a1>>a2;
        int ans=0;
        int m1,m2;
        for(int w=0;w<a1.size();w++){
            if(a1[w]=='b')m1=w;
            if(a2[w]=='b')m2=w;
        }
        for(int w=1;w<=n;w++){
            if(m2-m1==a[w].m2-a[w].m1&&a1.size()-m1>=a[w].l-a[w].m1&&m1>=a[w].m1)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
