#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int d[N][2];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int di=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j){
                if(a[i]==k){
                    d[di++][0]=i;d[di][1]=j;
                    ans++;
                }
            }else{
                bool xb=true;
                int x=a[i];
                for(int p=i+1;p<=j;p++){
                    x^=a[p];
                    if(a[p-1]!=a[p]){
                        xb=false;
                    }
                }
                if(x==k and xb==false){
                    d[di++][0]=i;d[di][1]=j;
                    ans++;
                }
            }
        }
    }
    int c=0;
    for(int i=0;i<di;i++){
        for(int j=i+1;j<di;j++){
            if(d[i][1]==0 or d[i][0]==0 or d[j][0]==0 or d[j][1]==0) continue;
            if(d[i][1]>=d[j][0]){
                if(d[i][1]-d[i][0]>d[j][1]-d[i][0]){
                    d[i][1]=d[i][0]=0;
                    ans--;
                    c++;
                }
                else{
                    d[j][1]=d[j][0]=0;
                    ans--;
                    c++;
                }

            }
        }
    }
    cout<<ans;
    return 0;
}
