#include <iostream>
#include <algorithm>
using namespace std;
int n,m,num;
int arr[105];
int brr[105][105];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int me;
    scanf("%d%d",&n,&m);
    num=n*m;
    for(int i=1;i<=num;i++){
        scanf("%d",&arr[i]);
        if(i==1){
            me=arr[i];
        }
    }
    sort(arr+1,arr+num+1,cmp);
    int idx=1;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                brr[j][i]=arr[idx];
                idx++;
            }
        }else{
            for(int j=1;j<=n;j++){
                brr[j][i]=arr[idx];
                idx++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(me==brr[i][j]){
                printf("%d %d",j,i);
                return 0;
            }
            //cout<<brr[i][j]<<" ";
        }
        //cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
