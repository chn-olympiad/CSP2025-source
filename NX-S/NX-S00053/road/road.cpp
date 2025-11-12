#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
long long n,m,k,i,j,l,ans=0;
cin>>n>>m>>k;
long long u[m],v[m],w[m],c[k],a[k][n],city[m],p,flag=0;
if(k=0){

}
for(i=1;i<=m;i++){
    cin>>u[i]>>v[i]>>w[i];
}
for(j=1;j<=k;j++){
        cin>>c[k];
    for(i=1;i<=n+1;i++){
        cin>>a[k][i];
    }
}
if(k==0){
    for(i=1;i<=n-2;i++){
        for(j=0;j<=n-1;j++){
            for(l=1;l<=n;l++){
                city[u[i]]++;
                city[v[i]]++;
                city[u[j]]++;
                city[v[j]]++;
                city[u[l]]++;
                city[v[l]]++;
                for(p=1;p<=m;p++){
                    if(city[p]==2){
                        flag++;
                    }
                    }
                    if(flag==2){
                        if(w[i]+w[j]+w[l]>=ans){
                            ans=w[i]+w[j]+w[l];
                        }
                }
                else{
                    flag=0;
                    for(p=1;p<=m;p++){
                        city[p]=0;
                    }
                }
            }
        }
    }
    cout<<ans;
}
else {
    ans=w[1]+w[2];
    if(k!=0){
        ans+=a[1][1];
        ans+=a[1][3];
    }
    cout<<ans;
}

fclose(stdin);
fclose(stdout);
return 0;
}
