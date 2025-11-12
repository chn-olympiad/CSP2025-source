#include<bits/stdc++.h>
using namespace std;
int const N=1e5+10;
struct node{
    int c1,c2,c3;
    bool f;
}a[N];
bool cmp(node x,node y){
    return x.c1>y.c1;
}
int aa[N][5];
int t,n,cnt=0;
int club[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int sss=t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i].c1,&a[i].c2,&a[i].c3);
        }
        if(a[1].c1!=0&&a[1].c2==0&&a[1].c3==0&&a[2].c2==0&&a[3].c3==0&&a[4].c2==0&&a[5].c2==0){

        }else{
            break;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n/2;i++){
            cnt+=a[i].c1;
        }
        cout<<cnt<<endl;
    }
    while(t--){
        if(t==sss-1){
            for(int i=1;i<=n;i++){
                aa[i][1]=a[i].c1;
                aa[i][2]=a[i].c2;
                aa[i][3]=a[i].c3;
            }
        }else{
            cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&aa[i][1],&aa[i][2],&aa[i][3]);
        }
        }
        for(int i=1;i<=n;i++){
            int max1=-1,mid1=-1,min1=-1,maxp,midp,minp;
            for(int k=1;k<=3;k++){
                if(aa[i][k]>max1){
                    max1=aa[i][k];
                    maxp=k;
                    continue;
                }
                if(max1!=-1&&aa[i][k]>mid1){
                    mid1=aa[i][k];
                    midp=k;
                    continue;
                }
                min1=aa[i][k];
                minp=k;
            }
            for(int k=1;k<=3;k++){
                if(aa[i][k]>max1){
                    max1=aa[i][k];
                    maxp=k;
                    continue;
                }
                if(max1!=-1&&aa[i][k]>mid1){
                    mid1=aa[i][k];
                    midp=k;
                    continue;
                }
                min1=aa[i][k];
                minp=k;
            }
            if(club[maxp]<n/2){
                cnt+=aa[i][maxp];
                club[maxp]++;
                continue;
            }
            if(club[midp]<n/2){
                cnt+=aa[i][midp];
                club[midp]++;
                continue;
            }
            club[minp]++;
            cnt+=aa[i][minp];
        }
        memset(club,0,sizeof(club));
        cout<<cnt<<endl;
    }




    fclose(stdin);
    fclose(stdout);
    return 0;
}


