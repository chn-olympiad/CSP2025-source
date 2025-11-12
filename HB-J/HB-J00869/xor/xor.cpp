#include<bits/stdc++.h>
using namespace std;
int n,k,z,a[500005];
int y(int a,int b){return (a|b)-(a&b);}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(k==0)for(int i=1;i<=n;i++){
        if(a[i]==0)z++;
        else if(a[i+1]==1)z++,i++;
    }
    else if(k==1)for(int i=1;i<=n;i++){if(a[i]==1)z++;}
    else for(int i=1;i<=n;i++){
        int x=a[i];
        for(int j=i+1;j<=n;j++){
            x=y(x,a[j]);
            if(x==k||a[j]==k){
                z++;
                i=j+1;
                break;
            }
        }
    }
    cout<<z;
    return 0;
}
