#include <bits/stdc++.h>
using namespace std;
bool vis[50005];
int n,a[50005],ans;
void mj(int i,int summ,int maxx,int k,int last){
    if(i == k+1){
        if(summ > maxx*2){
            ans++;
        }
        return ;
    }
    for(int j = last;j <= n;j++){
        mj(i+1,summ+a[j],max(maxx,a[j]),k,j+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 3;i <= n;i++){
        mj(1,0,0,i,1);
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}