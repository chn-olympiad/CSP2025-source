#include<bits/stdc++.h>
using namespace std;
int c[5005]{};
int a;
long long sum2=0,ans=0;
long long sum=0;
bool check(int m,int n){
    if(m>2*n){
        return 1;
    }
    return 0;
}
void aq(int q,int aqmax){
    for(int i=q;i<=a-1;i++){
        if(sum2==0)aqmax=c[i];
         sum2++;
         sum+=c[i];
        if(sum2>=3){
            if(check(sum,aqmax)==1){
                ans++;
             //   cout<<sum2<<" ";
            }
        }
        //cout<<sum<<" "<<aqmax<<" "<<sum2<<endl;
        if(i!=a-1)
        aq(i+1,aqmax);
        sum2--;
        sum-=c[i];
    }
}

int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=0;i<=a-1;i++){
        cin>>c[i];
    }
    sort(c,c+a,greater<int>());
    aq(0,c[0]);
    cout<<ans;

    return 0;
}
