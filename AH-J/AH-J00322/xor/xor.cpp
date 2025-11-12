//freopen
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,b[2000005],pre[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    int lst=0;
    b[0]=1;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^a[i];
        if(b[pre[i]^k]){
            cnt++;
            for(int j=lst;j<i;j++){
                b[pre[j]]=0;
            }
            lst=i;
        }
        b[pre[i]]=1;
    }
    cout<<cnt;
    return 0;
}
//小A（跟我rks差不多）：你b1是多少？我不信你能有我高
//我：你多少？
//小A：Diamond Dust AT 单曲rks16.61黄键送分大水谱
//我：啊？交互不会 但我b1比你高，16.70
//小A：夺少？16.70？
//我：是的，QZKago Requiem AT99.09
//小A：……
//（我rks16.22 小Arks16.15）
