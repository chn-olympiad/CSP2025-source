#include<bits/stdc++.h>
using namespace std;

long long n,t,k[5],cnt;
struct club{
    int x;
    int y;
}a[100005],b[100005],c[100005];

bool cmp(club k1,club k2){
    return k1.y<k2.y;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        cnt=0;k[1]=0;k[2]=0;k[3]=0;
        for(int i=1; i<=n; i++){
            int a1,b1,c1;
            cin >> a1 >> b1 >> c1;
            if(a1>=max(b1,c1)){
                k[1]++;
                a[k[1]].x=a1;
                a[k[1]].y=a1-max(b1,c1);
                cnt+=a1;
            }
            else if(b1>=max(a1,c1)){
                k[2]++;
                b[k[2]].x=b1;
                b[k[2]].y=b1-max(a1,c1);
                cnt+=b1;
            }
            else if(c1>=max(a1,b1)){
                k[3]++;
                c[k[3]].x=c1;
                c[k[3]].y=c1-max(a1,b1);
                cnt+=c1;
            }
        }
        //printf("%d %d %d %d\n",b[1].y,b[2].y,b[3].y,b[4].y);
        if(k[1]>n/2){
            sort(a+1,a+k[1]+1,cmp);
            for(int i=1; k[1]>n/2; i++){
                cnt-=a[i].y;
                k[1]--;
            }
        }
        else if(k[2]>n/2){
            sort(b+1,b+k[2]+1,cmp);
            for(int i=1; k[2]>n/2; i++){
                cnt-=b[i].y;
                k[2]--;
            }
        }
        else if(k[3]>n/2){
            sort(c+1,c+k[3]+1,cmp);
            for(int i=1; k[3]>n/2; i++){
                cnt-=c[i].y;
                k[3]--;
            }
        }
        printf("%lld\n",cnt);
    }

    return 0;
}

