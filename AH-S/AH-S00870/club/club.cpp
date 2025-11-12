#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,t1,t2,t3;
struct str{
    int m,id;
}b[100005][5];
int a[500005],p,x[100005][5];
bool cmp(int x,int y){
    return x>y;
}
bool flll;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int sum=0;
        flll=0;
        p=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[++p];
                x[i][j]=a[p];
                b[i][j].m=a[p];
                b[i][j].id=j;
            }
            if(x[i][1]!=0&&x[i][2]!=0||x[i][2]!=0&&x[i][3]!=0||x[i][1]!=0&&x[i][3]!=0){
                flll=1;
            }
        }
        sort(a+1,a+1+p,cmp);
        if(flll==0){
            for(int i=1;i<=n/2;i++){
                sum+=a[i];
            }
            cout<<sum<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            sum+=max(max(x[i][1],x[i][3]),x[i][2]);
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
