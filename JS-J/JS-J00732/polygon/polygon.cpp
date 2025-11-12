#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010],n,c[5010];
long long ans,k;
void bfs(int x,int d){
    if(x>=n){
        return;
    }
    for(int i=x;i<n;i++){
        c[d]=i;
        k=0;
        for(int j=1;j<=d;j++){
            k+=a[c[j]];
        }
        if(k>(2*a[c[d]])&&d>=3){
            ans++;
            for(int j=1;j<=d;j++){
                //cout<<c[j]+1<<" ";
            }
            //cout<<endl;
        }
        bfs(i+1,d+1);
    }
}

int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);
bfs(0,1);
cout<<ans;
}
