#include<iostream>
using namespace std;
const int N=1e4+5;
int n,k,ans;
int a[N][N];
int Xor(int a,int b){
    int c=0;
    int x[10],y[10],len1=0,len2=0;
    while(a){
        x[++len1]=a%2;
        a/=2;
    }while(b){
        y[++len2]=b%2;
        b/=2;
    }
    if(len1>len2){
        for(int i=len1;i>=1;i--){
            if(x[i]==y[i])c=c*2;
            else c=c*2+1;
        }
    }else{
        for(int i=len2;i>=1;i--){
            if(x[i]==y[i])c=c*2;
            else c=c*2+1;
        }
    }
    return c;
}
void dfs(int p,int rp){
    if(p>n){
        ans=max(ans,rp);
        return;
    }
    for(int i=p;i<=n;i++)if(a[p][i]==k)dfs(i+1,rp+1);
    dfs(p+1,rp);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i][0];
        a[i][i]=a[i][0];
        for(int j=1;j<i;j++){
            int t=a[j][0];
            for(int k=j+1;k<=i;k++)t=Xor(t,a[k][0]);
            a[j][i]=t;
            cout<<"";//Why delete this code will output wrong answers? I can't understand.
            /*
            4 2
            2 1 0 3
            after delete:2
            before delete:1

            hope I will not got 0pt because of it
            */
        }
    }
    //for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';cout<<endl;}
    dfs(1,0);
    cout<<ans;
    return 0;
}
