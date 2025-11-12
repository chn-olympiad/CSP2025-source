#include<bits/stdc++.h>
using namespace std;
int f[100005][5],b[100005][5][5],n;
struct node{
    int fi,se,th;
}a[100005];
bool cmp(node x,node y){
    int a1=x.fi+x.se+x.th;
    int b1=y.fi+y.se+y.th;
    return a1>=b1;
}
void special1(){
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n/2;i++){
       ans+=a[i].fi+a[i].se+a[i].th;
    }
    cout<<ans<<endl;
    return ;
}
void special2(){

    return ;
}
int maxn=0,num1,num2,num3;
void special3(int k,int num){
    if(k>n){
        maxn=max(maxn,num);
    }
    num1++;
    if(num1<=n/2)special3(k+1,num+a[k].fi);
    num1--;
    num2++;
    if(num2<=n/2)special3(k+1,num+a[k].se);
    num2--;
    num3++;
    if(num3<=n/2)special3(k+1,num+a[k].th);
    num3--;
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        memset(f,0,sizeof(f));
        memset(b,0,sizeof(b));
        cin>>n;
        int maxnum=n/2,flag1=0,flag2=0,flag3=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].fi,&a[i].se,&a[i].th);
            if(a[i].se!=0)flag1=1;
            if(a[i].th!=0)flag2=1;
            if(a[i].fi!=0)flag3=1;
        }
        //骗分A
        if(flag1+flag2+flag3==1){
            special1();
            continue;
        }
        //骗分B
        //if(flag1==1&&flag2==0){
         //   special1();
         //   continue;
       // }
        if(n==2){
            int pf1=0;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i==j)continue;
                    int x1,x2;
                    if(i==1)x1=a[1].fi;
                    if(i==2)x1=a[1].se;
                    if(i==3)x1=a[1].th;

                    if(j==1)x2=a[2].fi;
                    if(j==2)x2=a[2].se;
                    if(j==3)x2=a[2].th;
                    pf1=max(pf1,x1+x2);
                    //cout<<pf1<<" "<<endl;
                }
            }
            cout<<pf1<<endl;
            continue;
        }

        //2~15暴力
        if(2<=n&&n<=15){
            num1=0,num2=0,num3=0;
            special3(1,0);
            cout<<maxn<<endl;
            maxn=0;
            continue;
        }
        //以下过程可能能通过样例15，16 采取简易版dp+贪心
        sort(a+1,a+1+n,cmp);
        f[1][1]=a[1].fi;
        f[1][2]=a[1].se;
        f[1][3]=a[1].th;
        b[1][1][1]++;
        b[1][2][2]++;
        b[1][3][3]++;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=3;j++){
                int ans1,ans2,ans3;
                if(j==1)ans1=ans2=ans3=a[i].fi;
                if(j==2)ans1=ans2=ans3=a[i].se;
                if(j==3)ans1=ans2=ans3=a[i].th;
                ans1+=f[i-1][1];
                ans2+=f[i-1][2];
                ans3+=f[i-1][3];
                if(b[i-1][1][j]+1>maxnum)ans1=-1;
                if(b[i-1][2][j]+1>maxnum)ans2=-1;
                if(b[i-1][3][j]+1>maxnum)ans3=-1;
                if(ans1>=ans2&&ans1>=ans3&&ans1!=-1){
                        f[i][j]=ans1;
                        b[i][j][1]=b[i-1][1][1];
                        b[i][j][2]=b[i-1][1][2];
                        b[i][j][3]=b[i-1][1][3];
                        b[i][j][j]=b[i-1][1][j]+1;
                }
                if(ans2>=ans1&&ans2>=ans3&&ans2!=-1){
                        f[i][j]=ans2;
                        b[i][j][1]=b[i-1][2][1];
                        b[i][j][2]=b[i-1][2][2];
                        b[i][j][3]=b[i-1][2][3];
                        b[i][j][j]=b[i-1][2][j]+1;
                }
                if(ans3>=ans2&&ans3>=ans1&&ans3!=-1){
                        f[i][j]=ans3;
                        b[i][j][1]=b[i-1][3][1];
                        b[i][j][2]=b[i-1][3][2];
                        b[i][j][3]=b[i-1][3][3];
                        b[i][j][j]=b[i-1][3][j]+1;
                }
            }
        }
        cout<<max(f[n][1],max(f[n][2],f[n][3]))<<endl;
    }
    return 0;
}
//final AFO
//by sudajones
//废了
