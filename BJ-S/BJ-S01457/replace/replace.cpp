#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
string s1[N],s2[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        string x,y,xx,yy;
        cin>>x>>y;
        int sum=0;
        for(int i=0;i<n;i++){
            int a=x.find(s1[i]),b=y.find(s2[i]);
            if(a!=-1&&b!=-1){
                xx=x,yy=y;
                x.erase(a,s1[i].size()),y.erase(b,s2[i].size());
                //cout<<xx<<' '<<a<<' '<<yy<<' '<<b<<endl;
                //cout<<s1[i]<<' '<<s2[i]<<endl;
                if(x==y)sum++;
            }
            x=xx,y=yy;
        }
        cout<<sum<<endl;
    }
    return 0;
}