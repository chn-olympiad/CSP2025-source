#include<bits/stdc++.h>
using namespace std;
int a[5];
int n;
int b1[5],b[5][100005];
void cha(int x,int z){
    int y;
    if (b1[x]<n/2+1) y=b1[x];
    else y=n/2+1;
    b[x][y]=z;
    while(b[x][y]<b[x][y/2] && y!=1){
        swap(b[x][y],b[x][y/2]);
        y/=2;
    }
}
int shan(int x){
    int y=1;
    int z=b[x][1];
    b[x][1]=b[x][n/2+1];
    b[x][n/2+1]=0;
    while(y*2<=n/2){
        if(b[x][y*2]<b[x][y*2+1] || b[x][y*2+1]==0){
            if (b[x][y]>b[x][y*2]){
                swap(b[x][y],b[x][y*2]);
                y*=2;
            }
            else break;
        }
        else{
            if (b[x][y]>b[x][y*2+1]){
                swap(b[x][y],b[x][y*2+1]);
                y=y*2+1;
            }
            else break;
        }
    }
    return z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int dai;
        long long ans=0;
        for (int i=1;i<=n;i++){
            cin>>a[1]>>a[2]>>a[3];
            int maxn=max(max(a[1],a[2]),a[3]);
            if (maxn==a[1]){
                dai=a[1]-max(a[2],a[3]);
                b1[1]++;
                ans+=a[1];
                if (dai==0) cha(1,-1);
                else cha(1,dai);
                if (b1[1]>n/2){
                    int s=shan(1);
                    if (s!=-1) ans-=s;
                }
            }
            else if (maxn==a[2]){
                dai=a[2]-max(a[1],a[3]);
                b1[2]++;
                ans+=a[2];
                if (dai==0) cha(2,-1);
                else cha(2,dai);
                if (b1[2]>n/2){
                    int s=shan(2);
                    if (s!=-1) ans-=s;
                }
            }
            else if (maxn==a[3]){
                dai=a[3]-max(a[2],a[1]);
                b1[3]++;
                ans+=a[3];
                if (dai==0) cha(3,-1);
                else cha(3,dai);
                if (b1[3]>n/2){
                    int s=shan(3);
                    if (s!=-1) ans-=s;
                }
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=3;i++) b1[i]=0;
        for(int i=1;i<=n;i++){
            b[1][i]=0;
            b[2][i]=0;
            b[3][i]=0;
        }
    }
    return 0;
}