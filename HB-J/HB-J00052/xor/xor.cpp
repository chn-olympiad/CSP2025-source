//dep(i,a,b)for(i=a;i>=b;i--)
//rep(i,a,b)for(i=a;i<=b;i++)
#include<bits/stdc++.h>
using namespace std;
struct aaa{
    int left;
    int right;

    friend bool operator<(aaa a,aaa b){
        return a.left<b.left;
    }
}xy[500007];
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    int a[500007]={0};
    int qiansum[500007]={0};
    int n;
    int snum=0,sum=0;
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        qiansum[i]-qiansum[i-1] xor a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;i++){
                if((qiansum[j] xor qiansum[i-1])==k){
                    xy[snum+1].left=i;
                    xy[snum+1].right=j;
                    break;
                }
        }
    }
   sort(xy+1,xy+1+snum);
   int j=1;
int i=xy[j].left;
   while(i<=n){
    sum++;
    i=xy[j].right;
    for(int k=j+1;k<=snum;k++){
        if(xy[k].left>xy[j].right){
            j=k;
            break;
        }
    }
   }
   cout<<sum;
    return 0;
}
