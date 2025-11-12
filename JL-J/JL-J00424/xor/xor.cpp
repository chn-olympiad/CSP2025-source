#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],sum=0;
int check(int x,int y){
    int ans=0;
    ans=a[x];
    for(int i=x+1;i<y;i++){
        ans=ans^a[i];
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                sum++;
            }
        }
        cout<<sum<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==m) sum++;
        for(int j=i+1;j<n;j++){
            if(check(i,j)==m) sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
