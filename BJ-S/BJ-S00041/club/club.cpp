#include<bits/stdc++.h>
using namespace std;

long long T,n,cnt,t[100],b[200100],f[200100],k,sum,a[10][200100],c[200100];
void fd(long long x){
    if(a[1][x]>a[2][x]&&a[1][x]>a[3][x]){
        f[x]=1;
        b[x]=a[1][x]-max(a[2][x],a[3][x]);
    }else if(a[2][x]>=a[1][x]&&a[2][x]>a[3][x]){
        f[x]=2;
        b[x]=a[2][x]-max(a[1][x],a[3][x]);
    }else{
        f[x]=3;
        b[x]=a[3][x]-max(a[1][x],a[2][x]);
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        t[1]=t[2]=t[3]=cnt=0;
        k=-1;
        sum=0;
        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >> a[j][i];
            }
        }
        for(int i=1;i<=n;i++){
            fd(i);
            t[f[i]]++;
            cnt+=a[f[i]][i];
        }
        if(t[1]>n/2){
            k=1;
        }else if(t[2]>n/2){
            k=2;
        }else if(t[3]>n/2){
            k=3;
        }
        if(k==-1){
            cout << cnt << endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(f[i]==k){
                sum++;
                c[sum]=b[i];
            }
        }
        sort(c+1,c+1+sum);
        for(int i=1;i<=t[k]-n/2;i++){
            cnt-=c[i];
        }
        cout << cnt << endl;
       /* for(int i=1;i<=n;i++){
            cout << f[i] << ' ' << b[i] << ' ' << c[i] << endl;
        }*/
        //cout << t[1] << ' '<< t[2] <<" " << t[3] << ' ' << k;
    }




























































































    return 0;
}
