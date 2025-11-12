#include<iostream>
using namespace std;
int n,k;
int a[500005],sum[500005],f[10005][10005],ans[10005],ans_max[10005];
bool B=1;
int B_num1;
//void DFS(int l){
//    cout<<l<<' ';
//    if(l==n+1){
//        ans++;
//        return;
//    }
//    for(int i=l;i<=n;i++){
//        if(f[l][i]){
//            DFS(i+1);
//        }
//    }
//    return;
//}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) B=0;
        B_num1+=a[i];
        sum[i]=sum[i-1]^a[i];
    }
    if(B){
        if(k==0) cout<<B_num1/2<<endl;
        else if(k==1) cout<<B_num1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                f[i][j]=1;
                //cout<<sum[j]<<'^'<<sum[i-1]<<'='<<(sum[j]^sum[i-1])<<endl;
            }
        }
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++){
    //        cout<<f[i][j]<<' ';
    //    }
    //    cout<<endl;
    //}
    //DFS(1);
    ans[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            //cout<<i<<','<<j<<' '<<ans[j-1]<<'*'<<f[j][i]<<endl;
            if(f[j][i]){
                ans[i]=max(ans[i],ans_max[j-1]+1);
            }
        }
        ans_max[i]=max(ans_max[i-1],ans[i]);
    }
    //for(int i=1;i<=n;i++){
    //    cout<<ans[i]<<' ';
    //}
    //cout<<endl;
    //for(int i=1;i<=n;i++){
    //    cout<<ans_max[i]<<' ';
    //}
    //cout<<endl;
    cout<<ans_max[n]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
