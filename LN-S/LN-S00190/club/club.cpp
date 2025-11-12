#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100100],b[100100],c[100100],d[100100],det[100100],h[4],k,cnt,mp[100100];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        int temp =0;
        memset(mp,0,sizeof(mp));
        h[1]=h[2]=h[3]=0;
        cnt=0;
        cin >>n;
        for(int i =1 ;i <= n ;i++){
            scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
            if(a[i]>= b[i] && a[i] >=c[i]){
                d[i]=1;
                h[1]++;
                det[i]=a[i]-max(b[i],c[i]);
                cnt+=a[i];
            }
            else if(b[i] >=a[i] && b[i] >=c[i]){
                d[i]=2;
                h[2]++;
                det[i]=b[i]-max(c[i],a[i]);
                cnt+=b[i];
            }
            else{
                d[i]=3;
                h[3]++;
                det[i]=c[i]-max(a[i],b[i]);
                cnt+=c[i];
            }
        }
        if(h[1]<=n/2 && h[2] <= n/2&& h[3] <= n/2){
            cout <<cnt <<endl;
            continue;
        }
        else{
            if(h[1] > n/2){
                k=1;
            }
            else if(h[2] > n/2){
                k=2;
            }
            else{
                k=3;
            }
            for(int i = 1 ;i <= n ; i++){
                if(d[i] == k){
                    mp[++temp]=det[i];
                }
            }
            sort(mp+1,mp+temp+1);
            int now =1;
            while(h[k]>n/2){
                cnt-= mp[now++];
                h[k]--;
            }
        }
        cout <<cnt <<endl;
    }
    return 0;
}
