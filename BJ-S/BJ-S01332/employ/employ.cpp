#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long n,m,a[600],q,w,sum1=1,e,vis[600],sum;
string s;
void f(int x,int r,int q1){
    if(x==n+1&&r>=m){
        sum++,sum%=N;
        //cout<<r<<" "<<q1<<endl;
        return ;
    }
    if(x>n)return;
    //if(n-x+r<m)return;
    if(s[x]=='0'){
        f(x+1,r,q1+1);
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]>=q1||vis[i]==0){
                vis[i]=1;
                f(x+1,r+1,q1);
                vis[i]=0;
            }
        }
    }

}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)q++;
    }
    if(m==1){
        for(int i=0;i<n;i++){
            if(s[i]=='0')w++;
            else e++;
        }
        for(int i=1;i<=e;i++){
            sum1*=i,sum1%=N;
        }
        cout<<(w*(n-q)*sum1)%N;
    }else{
        s=" "+s;
        f(1,0,0);
        cout<<sum;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
