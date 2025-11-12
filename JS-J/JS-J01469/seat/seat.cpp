//aob
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileopen(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
int a[100007];
signed main(){
    fileopen("seat");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,i,j;
    cin>>m>>n;//行列反了一下，所以n,m也要换(?)
    for(i=1;i<=n*m;i++)cin>>a[i];
    int x=a[1];
    sort(a+1,a+n*m+1);
    int p=lower_bound(a+1,a+n*m+1,x)-a;
    p=n*m-p+1;
    for(i=1;i<=n;i++){
        if(p>m){
            p-=m;
            continue;
        }
        cout<<i<<' ';
        if(i%2==1)cout<<p;
        else cout<<m-p+1;
        exit(0);
    }
    return 0;
}
//iao
/*
考虑表示为(列，行)
则为1 1->1 2->1 3->1 4->2 4->2 3->2 2-> 2 1->3 1->...
9:03 开写
9:10 过了大样例
9:13 疑似找到hack
9:15 这次应该过了（神奇大样例不给n!=m的点）
*/
