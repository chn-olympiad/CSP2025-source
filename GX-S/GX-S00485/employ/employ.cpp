#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
bool bj[505];
string s;
long long sum=0;
void f(int x,int ceng,int an){
    if(ceng==m){
        sum=(sum+1)%998244353;
        return;
    }
    int y=0;
    for(int i=1;i<=n;i++){
        if(bj[i]==0&&c[i]>an){
            bj[x]=1;
            f(i,ceng+1,an);
            bj[x]=0;

        }
        else{
            y++;
        }
    }
    an+=y;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        if(c[i]!=0) f(i,2,0);
    }
    cout<<sum;
    return 0;
}
