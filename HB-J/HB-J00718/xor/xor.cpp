# include <bits/stdc++.h>
using namespace std;
int n,k,a[100100],vis[100100],len[100010],v[1010][22];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int cnt=0,ans=0;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        if(a[i]==k) ans++,vis[i]=1;
        int x=a[i];
        while(x>0){
            v[i][++len[i]]=x%2;
            x/=2;
        }
    }
    //cout<<ans<<"\n\n";
    for(int i=1; i<=n;){
        //cout<<i<<"\n";
        if(vis[i]){
            i++;
            continue;
        }
        int bz=0,t[100]={0},m=0;
        for(int j=i; j<=n; j++){
            if(vis[j]) break;
            m=max(m,len[j]);
            int x=0,f=1;
            for(int l=1; l<=m; l++) t[l]=(t[l]+v[j][l])%2;
            for(int l=1; l<=m; l++){
                x+=f*t[l];f*=2;
            }
            //cout<<"    ";
            //for(int l=m; l>=1; l--) cout<<t[l]<<" ";
            //cout<<"    "<<k<<" "<<x<<"\n";
            if(x==k){
                ans++;
                bz=1,i=j+1;
                break;
            }
        }
        if(bz==0) i++;
    }
    cout<<ans;
    return 0;
}
