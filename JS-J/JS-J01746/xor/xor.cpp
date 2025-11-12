#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int vis[500010];
unsigned long long ans;
bool flag=0;
int h;
void dfs(int l,int r,int val){
    if(val>=k||flag){
        if(val==k&&!flag){
            ans++;
            h=r+1;

        }
        flag=1;
        return;
    }
    if(val<k&&r<n){
        r++;
        int f=val;

        val=(val^a[r]);


        dfs(l,r,val);
        val=f;
        r--;
    }






}
int main(){
    ifstream in("xor.in");
    ofstream out("xor.out");
    in>>n>>k;
    for(int i=1;i<=n;i++){
        in>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(flag){
            i=h;
        }
        flag=0;
        dfs(i,i,a[i]);
    }
    out<<ans;



    return 0;
}
