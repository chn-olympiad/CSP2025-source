#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
struct p{
    string x,y;
}a[N];
long long n,m,s;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    while(m--){
        s=0;
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        for(long long k=0;k<n;k++){
            for(long long i=0;i<t1.size();i++){
                string zj=a[k].x,th=a[k].y;
                long long f=1;
                for(long long j=i;j<i+zj.size();j++){
                    if(t1[j]!=zj[j-i]){
                        f=0;
                        break;
                    }
                }
                if(f){
                    string xt1=t1;
                    for(long long j=i;j<i+zj.size();j++) xt1[j]=th[j-i];
                    if(!(xt1>t2||xt1<t2)) s++;
                }
            }
        }

        cout<<s<<endl;
    }

    return 0;
}
