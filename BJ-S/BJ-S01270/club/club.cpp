#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct node{
    int a,b,c;
}hh[100005];
int num1,num2,num3;
vector<int>a,b,c;
long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
     //   cout<<
        num1=num2=num3=0;
        ans=0;
        a.clear();
        b.clear();
        c.clear();
        for(int i=1;i<=n;i++){
            cin>>hh[i].a>>hh[i].b>>hh[i].c;
            ans+=max(hh[i].a,max(hh[i].b,hh[i].c));
            if(hh[i].a>=hh[i].b && hh[i].a>=hh[i].c){
                a.push_back(hh[i].a-max(hh[i].b,hh[i].c));
                num1++;
            }
            else if(hh[i].b>=hh[i].a && hh[i].b>=hh[i].c){
                b.push_back(hh[i].b-max(hh[i].a,hh[i].c));
                num2++;
            }
            else{
                c.push_back(hh[i].c-max(hh[i].a,hh[i].b));
                num3++;
            }
        }
        if(num2>num1)swap(a,b),swap(num1,num2);
            if(num3>num1)swap(a,c),swap(num1,num3);
            if(num1>n/2)sort(a.begin(),a.end());
            for(int i=0;i<num1-n/2;i++){
                ans-=a[i];
        }
        cout<<ans<<"\n";
    }
}
