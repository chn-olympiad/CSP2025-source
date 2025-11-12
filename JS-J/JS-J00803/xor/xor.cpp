#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,k;
int arr[1005];
int brr[1005][1005];
struct node{
    int s,e;
}crr[1000005];
bool cmp(node x,node y){
    return x.e<y.e;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            brr[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(brr[i][j-1]==-1){
                brr[i][j]=arr[j];
            }else{
                brr[i][j]=brr[i][j-1]^arr[j];
            }
//            int sum=arr[i];
  //          for(int h=i+1;h<=j;h++){
    //            sum^=arr[h];
      //      }
        //    brr[i][j]=sum;
        }
    }
    int idx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(brr[i][j]==k){
                node temp;
                temp.s=i;
                temp.e=j;
                crr[idx]=temp;
                idx++;
            }
            //cout<<brr[i][j]<<" ";
        }
        //cout<<endl;
    }
    sort(crr,crr+idx,cmp);
    int prev=crr[0].e;
    int ans=1;
    if(idx==0){
        printf("0");
        return 0;
    }
    for(int i=0;i<idx;i++){
        if(crr[i].s>prev){
            prev=crr[i].e;
            ans++;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
