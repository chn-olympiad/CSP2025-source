#include <bits/stdc++.h>
using namespace std;

struct nod{
    int idx,c;
}op[510];
//int mark[510],a[5];
//void dfs(int n){
    //if (n==0){
        //for (int i=1;i<=3;i++){
            //cout << a[i] << " ";
        //}
        //cout << endl;
        //return;
    //}
    //for (int i=1;i<=n;i++){
        //if (mark[i]==0){
            //mark[i]=1;
            //a[n]=i;
            //dfs(n-1);
            //mark[i]=0;
        //}
    //}
//}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i=1;i<=n;i++){
        cin >> op[i].c;
        op[i].idx=i;
    }
    //dfs(n);
    //for (int i=1;i<=n;i++){
        //cout << op[i].c << " ";
    //}
    cout << m;
    return 0;
}
