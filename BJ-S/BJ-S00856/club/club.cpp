#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][4],e,b[100001],cnt;
struct pp{
     int ch,jc;
}d[100001];
bool cmp(pp z,pp w){
    return z.ch>w.ch;
}
void dfs(int x,int y,int z,long long cnt1,int w){
    if(x>n/2||y>n/2||z>n/2) return;

    if(w==n+1){
        cnt=max(cnt,cnt1);
        return;
    }
    dfs(x+1,y,z,cnt1+a[w][1],w+1);
    dfs(x,y+1,z,cnt1+a[w][2],w+1);
    dfs(x,y,z+1,cnt1+a[w][3],w+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cnt=0;
        cin>>n;
        if(n==2){
            int q[7]={};
            for(int i=1;i<=6;i++) cin>>q[i];
            cout<<max(max(max((q[1]+q[5]),(q[1]+q[6])),max((q[2]+q[4]),(q[2]+q[6]))),max((q[3]+q[4]),(q[3]+q[5])))<<'\n';
            continue;
        }else if(n==4){
            for(int j=1;j<=n;j++){
                for(int i=1;i<=3;i++) cin>>a[j][i];
            }
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        for(int l=1;l<=3;l++){
                            int tong[5]={};
                            tong[i]++;
                            tong[j]++;
                            tong[k]++;
                            tong[l]++;
                            if(tong[1]>2||tong[2]>2||tong[3]>2) continue;
                            cnt=max(cnt,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
                        }
                    }
                }
            }
        }else if(n==10){
            for(int j=1;j<=n;j++){
                for(int i=1;i<=3;i++) cin>>a[j][i];
            }
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        for(int l=1;l<=3;l++){
                            for(int m=1;m<=3;m++){
                                for(int o=1;o<=3;o++){
                                    for(int p=1;p<=3;p++){
                                        for(int q=1;q<=3;q++){
                                            for(int r=1;r<=3;r++){
                                                for(int s=1;s<=3;s++){
                                                    int tong[11]={};
                                                    tong[i]++;
                                                    tong[j]++;
                                                    tong[k]++;
                                                    tong[l]++;
                                                    tong[m]++;
                                                    tong[o]++;
                                                    tong[p]++;
                                                    tong[q]++;
                                                    tong[r]++;
                                                    tong[s]++;
                                                    if(tong[1]>5||tong[2]>5||tong[3]>5) continue;
                                                    cnt=max(cnt,a[1][i]+a[2][j]+a[3][k]+a[4][l]+a[5][m]+a[6][o]+a[7][p]+a[8][q]+a[9][r]+a[10][s]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else{
            bool h=0,h1=0;
            for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
            for(int i=1;i<=n;i++){
                if(a[i][2]!=0){
                    h=1;
                    h1=1;
                    break;
                }
                if(a[i][3]!=0) h=1;
            }
            if(h==0&&h1==0){
                for(int i=1;i<=n;i++) b[i]=a[i][1];
                sort(b+1,b+n+1,greater<int>());
                for(int j=1;j<=n/2;j++) cnt+=b[j];
            }else if(h==0){
                for(int i=1;i<=n;i++){
                    d[i].jc=min(a[i][2],a[i][1]);
                    d[i].ch=a[i][2]-a[i][1];
                }
                sort(d+1,d+n+1,cmp);
                for(int i=1;i<=n;i++){
                    if(i<=n/2) cnt+=d[i].jc+d[i].ch;
                    else cnt+=max(d[i].jc-d[i].ch,d[i].jc);
                }
            }else{
                dfs(0,0,0,(long long)0,1);
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}

