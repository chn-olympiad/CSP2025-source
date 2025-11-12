#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005],sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }if(n>=3){
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int l=j+1;l<=n;l++)if(a[i]+a[j]+a[l]>max(max(a[i],a[j]),a[l])*2)sum++;
    }if(n>=4){
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int l=j+1;l<=n;l++)for(int k=l+1;k<=n;k++)if(a[i]+a[j]+a[l]+a[k]>max(max(max(a[i],a[j]),a[l]),a[k])*2)sum++;
    }if(n>=5){
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int l=j+1;l<=n;l++)for(int k=l+1;k<=n;k++)for(int x=k+1;x<=n;x++)if(a[i]+a[j]+a[l]+a[k]+a[x]>max(max(max(max(a[i],a[j]),a[l]),a[k]),a[x])*2)sum++;
    }if(n>=6){
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int l=j+1;l<=n;l++)for(int k=l+1;k<=n;k++)for(int x=k+1;x<=n;x++)for(int y=x+1;y<=n;y++)if(a[y]+a[i]+a[j]+a[l]+a[k]+a[x]>max(max(max(max(max(a[i],a[j]),a[l]),a[k]),a[x]),a[y])*2)sum++;
    }if(n>=7){
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int l=j+1;l<=n;l++)for(int k=l+1;k<=n;k++)for(int x=k+1;x<=n;x++)for(int y=x+1;y<=n;y++)for(int X=y+1;X<=n;X++)if(a[X]+a[y]+a[i]+a[j]+a[l]+a[k]+a[x]>max(max(max(max(max(max(a[i],a[j]),a[l]),a[k]),a[x]),a[y]),a[X])*2)sum++;
    }if(n>=8){
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int l=j+1;l<=n;l++)for(int k=l+1;k<=n;k++)for(int x=k+1;x<=n;x++)for(int y=x+1;y<=n;y++)for(int X=y+1;X<=n;X++)for(int Y=X+1;Y<=n;Y++)if(a[Y]+a[X]+a[y]+a[i]+a[j]+a[l]+a[k]+a[x]>max(max(max(max(max(max(max(a[i],a[j]),a[l]),a[k]),a[x]),a[y]),a[X]),a[Y])*2)sum++;
    }if(n>=9){
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int l=j+1;l<=n;l++)for(int k=l+1;k<=n;k++)for(int x=k+1;x<=n;x++)for(int y=x+1;y<=n;y++)for(int X=y+1;X<=n;X++)for(int Y=X+1;Y<=n;Y++)for(int I=Y+1;I<=n;I++)if(a[I]+a[Y]+a[X]+a[y]+a[i]+a[j]+a[l]+a[k]+a[x]>max(max(max(max(max(max(max(max(a[i],a[j]),a[l]),a[k]),a[x]),a[y]),a[X]),a[Y]),a[I])*2)sum++;
    }if(n==10){
        int s=0,maxx=0;
        for(int i=1;i<=n;i++){
            s+=a[i];
            maxx=max(a[i],maxx);
        }if(s>maxx*2){
            sum++;
        }
    }cout<<sum;
    return 0;
}
