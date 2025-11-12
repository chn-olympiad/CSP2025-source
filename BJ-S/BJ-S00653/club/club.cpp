#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int t111,n,size1,size2,size3;
long long ans;
struct data{
    int a1,a2,a3,c;
}a;
data club1[N],club2[N],club3[N];
bool rule(data x,data y){
    return x.c>y.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t111;
    while(t111--){
        ans=0,size1=0,size2=0,size3=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a.a1>>a.a2>>a.a3;
            if(a.a1>=a.a2&&a.a1>=a.a3){
                a.c=a.a1-max(a.a2,a.a3);
                club1[size1++]=a;
                ans+=a.a1;
            }else if(a.a2>=a.a3&&a.a2>=a.a1){
                a.c=a.a2-max(a.a1,a.a3);
                club2[size2++]=a;
                ans+=a.a2;
            }else{
                a.c=a.a3-max(a.a1,a.a2);
                club3[size3++]=a;
                ans+=a.a3;
            }
        }
        if(size1>(n/2)){
            sort(club1,club1+size1,rule);
            for(int i=size1;i>=n/2;i--){
                ans-=club1[i].c;
            }
        }else if(size2>(n/2)){
            sort(club2,club2+size2,rule);
            for(int i=size2;i>=n/2;i--){
                ans-=club2[i].c;
            }
        }else if(size3>(n/2)){
            sort(club3,club3+size3,rule);
            for(int i=size3;i>=2/n;i--){
                ans-=club3[i].c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}