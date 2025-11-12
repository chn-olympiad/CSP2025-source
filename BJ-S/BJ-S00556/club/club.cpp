#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100010][5];
int ans[50010][3][2];
int cnt[3];
void in1(int x,int w,int y){
    int k=1;
    while(w>ans[k][y][1] && k<cnt[y]){
        ans[k-1][y][1]=ans[k][y][1];
        ans[k-1][y][0]=ans[k][y][0];
        k++;
    }
    ans[k-1][y][1]=w;
    ans[k-1][y][0]=x;
}
void in(int y){
    for(int g=cnt[y]-1;g>=0;g--){
        ans[g+1][y][1]=ans[g][y][1];
        ans[g+1][y][0]=ans[g][y][0];
    }
}
void zhu(int x,int y,int b,int j){
    if(cnt[y]<b){
        cnt[y]++;
        in(y);
        in1(j,x,y);
        return;
    }
    else{
        int c=y,d=x;
        if(x>ans[0][y][1]){
            c=ans[0][y][0];
            d=ans[0][y][1];
            in1(j,x,y);
        }
        int e=-1,f;
        for(int k=1;k<=3;k++){
            if(a[c][k]<d && a[c][k]>e){
                e=a[c][k];
                f=k;
            }
        }
        zhu(e,f,b,c);
    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        memset(ans,0,sizeof(ans));
        cin>>n;
        int b=n/2;
        cnt[0]=0;
        cnt[1]=0;
        cnt[2]=0;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            a[j][4]=max(a[j][3],max(a[j][2],a[j][1]));
            for(int k=1;k<=3;k++){
                if(a[j][k]==a[j][4]){
                    a[j][0]=k-1;
                    break;
                }
            }
        }
        for(int j=1;j<=n;j++){
            zhu(a[j][4],a[j][0],b,j);
        }
        int ans1=0;
        //for(int j=0;j<cnt[0];j++) cout<<ans[j][0][1]<<endl;
        for(int j=0;j<cnt[0];j++) ans1+=ans[j][0][1];
        for(int j=0;j<cnt[1];j++) ans1+=ans[j][1][1];
        for(int j=0;j<cnt[2];j++) ans1+=ans[j][2][1];
        cout<<ans1<<endl;
    }
    return 0;
}
