#include <bits/stdc++.h>
using namespace std;
int a[500010],flag[500010];
int nx[100000010],ny[100000010],ans[100000010];
int xr(int x,int y){
    int cntx=0;
    while (x>0){
        cntx++;
        nx[cntx]=x%2;
        x/=2;
    }
    int cnty=0;
    while (y>0){
        cnty++;
        ny[cnty]=y%2;
        y/=2;
    }
    int flag=0;
    if (cntx>cnty){
        flag=0;
    }
    else{
        flag=1;
    }
    int cnta=0;
    while (1){
        if (cntx==0 || cnty==0){
            break;
        }
        cnta++;
        if (nx[cntx]==ny[cnty]){
            ans[cnta]=0;
        }
        else{
            ans[cnta]=1;
        }
        cntx--;
        cnty--;
    }
    if (flag==0){
        for (int i=cntx;i>=1;i--){
            cnta++;
            ans[cnta]=nx[cntx];
        }
    }
    else{
        for (int i=cnty;i>=1;i--){
            cnta++;
            ans[cnta]=ny[cnty];
        }
    }
    long long l=0;
    double cnt=0;
    for (int i=1;i<=cnta;i++){
        l+=ans[i]*pow(2.0,cnt);
        cnt++;
    }
    return l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int ans=0;
    int p=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]!=1){
            p=1;
        }
        if (a[i]==k){
            ans++;
            flag[i]=-1;
        }
    }
    if (p==0){
        cout<<n/2;
        return 0;
    }
    p=0;
    int cnt0=0,cnt1=0;
    for (int i=1;i<=n;i++){
        if (a[i]!=0 && a[i]!=1){
            p=1;
            break;
        }
        else{
            if (a[i]==0){
                cnt0++;
            }
            else{
                cnt1++;
            }
        }
    }
    if (p==0){
        if (k==1){
            int now0=0;
            for (int i=1;i<=n;i++){
                if (now0==3){
                    cnt1++;
                    now0=0;
                }
                if (a[i]==0){
                    now0++;
                }
            }
            cout<<cnt1;
            return 0;
        }
        else{
            int now1=0;
            for (int i=1;i<=n;i++){
                if (now1==3){
                    cnt0++;
                    now1=0;
                }
                if (a[i]==1){
                    now1++;
                }
            }
            cout<<cnt0;
            return 0;
        }
    }
    for (int i=1;i<=n;i++){
        if (flag[i]==0){
            int lst=i;
            int lstpos=-1;
            for (int j=i+1;j<=n;j++){
                if (flag[j]==-1){
                    break;
                }
                else{
                    lst=xr(lst,a[j]);
                    if (lst==k){
                        lstpos=j;
                        ans++;
                        break;
                    }
                }
            }
            for (int j=i;j<=lstpos;j++){
                flag[j]=-1;
            }
        }
    }
    cout<<ans;
    return 0;
}
