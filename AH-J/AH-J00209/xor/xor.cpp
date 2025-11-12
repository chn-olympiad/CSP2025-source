#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
long long as[500005];
bool vis[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1,a;i<=n;i++){
        cin>>a;
        as[i]=(as[i-1]^a);
    }
    for(int i=1;i<=n;i++){
        for(int p=0;p<=n-i;p++){
            int j=i+p;
            long long tmp=(as[j]^as[i-1]);
            if(tmp==k&&(!vis[i])&&(!vis[j])){
                cnt++;
                for(int q=i;q<=j;q++){
                    vis[q]=true;
                }
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
}
