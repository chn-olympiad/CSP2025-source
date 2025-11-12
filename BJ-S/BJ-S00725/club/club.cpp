#include<bits/stdc++.h>
using namespace std;

const int N=100000+10;
int n,a[N],b[N],c[N],ans=0,c1,c2,c3;
priority_queue<int,vector<int>,greater<int> >qa,qb,qc;
void test(){
    ans=c1=c2=c3=0;
    while(qa.size())qa.pop();
    while(qb.size())qb.pop();
    while(qc.size())qc.pop();
    cin>>n;for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]>=max(b[i],c[i])){
            //cout<<i<<"-->"<<a[i]<<endl;
            c1++;ans+=a[i];
            qa.push(a[i]-max(b[i],c[i]));
        }else if(b[i]>=max(a[i],c[i])){
            c2++;ans+=b[i];
            //cout<<i<<"-->"<<b[i]<<endl;
            qb.push(b[i]-max(a[i],c[i]));
        }else{
            c3++;ans+=c[i];
            //cout<<i<<"-->"<<c[i]<<endl;
            qc.push(c[i]-max(a[i],b[i]));
        }
    }
    int mx=n/2;
    //cout<<"\t"<<c1<<' '<<c2<<' '<<c3<<"; mx="<<mx<<endl;
    while(c1>mx)ans-=qa.top(),qa.pop(),c1--;
    while(c2>mx)ans-=qb.top(),qb.pop(),c2--;
    while(c3>mx)ans-=qc.top(),qc.pop(),c3--;
    cout<<ans<<endl;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;cin>>t;while(t--)test();
    return 0;
}
