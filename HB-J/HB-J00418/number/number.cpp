#include<bits/stdc++.h>
using namespace std;
int a,ans[1000005],cnt,maxx;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=1;i<=1000005;++i){
        ans[i]=a%10;
        a=a/10;
        cnt++;
        if(a==0){
            break;
        }
    }
    int sum[cnt];
    for(int i=1;i<=cnt;++i){
        for(int j=1;j<=cnt;++j){
            if(ans[j]!=-1&&ans[j+1]!=-1){
                if(ans[j]>ans[j+1]){
                    maxx=ans[j];
                }
                else if(ans[j]<=ans[j+1]){
                    maxx=ans[j+1];
                }
                sum[i]=maxx;
            }
        }
        int flag=1;
        for(int k=1;k<=cnt;++k){
            if(ans[k]==maxx&&flag==1){
                ans[k]=-1;
                flag=0;
            }
        }
    }
    for(int i=1;i<=cnt;++i){
        cout<<sum[i];
    }
    return 0;
}
