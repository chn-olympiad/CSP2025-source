#include<bits/stdc++.h>
using namespace std;
int r[3];
struct stu{
    int a,b,c;
    int fst(){
        return max(max(a,b),c);
    }
    int sec(){
        return max(min(a,b),min(b,c));
    }
    int fstp(){
        if(fst()==a){
            return 0;
        }else if(fst()==b){
            return 1;
        }else{
            return 2;
        }
    }
    int secp(){
        if(sec()==a){
            return 0;
        }else if(sec()==b){
            return 1;
        }else{
            return 2;
        }
    }
}a[100005];
bool cmp(stu a,stu b){
    return a.fst()-a.sec()>b.fst()-b.sec();
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(r,0,sizeof(r));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        sort(a+1,a+1+n,cmp);
        int ans=0;
        for(int i=1;i<=n;i++){
            int m=a[i].fstp(),e=a[i].secp();
            if(r[m]<n/2){
                ans=ans+a[i].fst();
                r[m]++;
            }else{
                ans=ans+a[i].sec();
                r[e]++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
