#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int b[5005];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long n,m,x=0,y=1,k=0,f=1;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==1){
        k++;
    }
}
if(k==n){
    for(int i=3;i<=n;i++){
        for(int j=0;j<i;j++){
            y*=(n-j);
            y/=(j+1);
        }
        x+=y;
        y=1;
    }
    cout<<x;
}
else if(n<=25){
        k=0;
    for(int i=1;i<=n;i++){
        f*=2;
    }
    for(int j=1;j<=f;j++){
        b[n]++;
        for(int v=n;v>1;v--){
            if(b[v]==2){
                b[v]=0;
                b[v-1]++;
            }
        }
        m=0;
        y=0;
        for(int v=1;v<=n;v++){
            y+=b[v]*a[v];
            m=max(m,a[v]*b[v]);
        }
        if(y>m*2){
            x++;
        }
    }
    cout<<x;
}
fclose(stdin);
fclose(stdout);
return 0;
}
