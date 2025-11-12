#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],l=1,r=1,x,cnt;
map<string,int> ch;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[i]==0||a[j]==0){
                continue;
            }
            string s;
            for(int k=i;k<=j;k++){
                x^=a[k];
                s=s+char(a[k]+48);
            }
            if(x==k&&ch[s]==0){
                cnt++;
                ch[s]++;
            }
            x=0;
        }
    }
    cout<<cnt;
    return 0;
}
