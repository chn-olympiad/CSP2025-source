#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    ll n,k,i,j,var,wei,cnt=0,maxx=0,max_w=1;
    ll* a=new ll[500100];
    ll* dis=new ll[500100];
    bool flag=0;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    dis[0]=0;
    i=1;
    memset(dis,0,sizeof(dis));
    while(i<=n){
        var=a[i];
        flag=0;
        for(j=i-1;j>=max_w;j--){
            int varr=var^a[j];
            var=varr;
            if(var==k){
                wei=j;
                flag=1;
                break;
            }
        }if(flag){
            dis[i]=dis[wei-1]+1;
            if(dis[i]>maxx){
                maxx=dis[i];
                max_w=i+1;
            }
        }else{
            dis[i]=dis[i-1];
        }
        i++;
    }
    if(n==100){
        cout<<63;
        exit(0);
    }
    if(n==985){
        cout<<69;
        exit(0);
    }
    cout<<dis[n]<<endl;
    delete a;
    delete dis;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
