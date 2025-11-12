#include<bits/stdc++.h>
using namespace std;
int t,n;
struct k{
    int s1,s2,s3;
}a[10010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int c[10]={0},c1=0,b[10010][3]={0,0},k=1,k1=1,k2=1,sum[10010]={0},b1[10010][3]={0,0};
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].s1>>a[i].s2>>a[i].s3;
            if(a[i].s1>a[i].s2&&a[i].s1>a[i].s3){
                    c[1]++;
                    c1+=a[i].s1;
                    b[k][1]=a[i].s1;
                    b1[k][1]=i;
                    k++;
            }
            else if(a[i].s2>a[i].s1&&a[i].s2>a[i].s3){
                    c[2]++;
                    c1+=a[i].s2;
                    b[k1][2]=a[i].s2;
                    b1[k1][2]=i;
                    k1++;
            }
            else{
                c[3]++;
                c1+=a[i].s3;
                b[k2][3]=a[i].s3;
                b1[k2][3]=i;
                k2++;
            }
        }
        if(c[1]>n/2){
            for(int i=1;i<=c[1];i++){
                sum[i]=b[i][1]-max(a[b1[i][1]].s2,a[b1[i][1]].s3);
            }
            sort(sum+1,sum+c[1]+1);
            for(int i=1;i<=c[1]-n/2;i++){
                c1-=sum[i];
            }
        }
        else if(c[2]>=n/2){
            for(int i=1;i<=c[2];i++){
                sum[i]=b[i][2]-max(a[b1[i][2]].s1,a[b1[i][2]].s3);
            }
            sort(sum+1,sum+c[2]+1);
            for(int i=1;i<=c[2]-n/2;i++){
                c1-=sum[i];
            }
        }
        else if(c[3]>n/2){
            for(int i=1;i<=c[3];i++){
                sum[i]=b[i][3]-max(a[b1[i][3]].s2,a[b1[i][3]].s1);
            }
            sort(sum+1,sum+c[3]+1);
            for(int i=1;i<=c[3]-n/2;i++){
                c1-=sum[i];
            }
        }
        cout<<c1<<endl;
    }
    return 0;
}


