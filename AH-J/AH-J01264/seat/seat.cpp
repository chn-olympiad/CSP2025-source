#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=106;
struct node{
    int id=0;
    int cj;
}sr[N];
bool cmp(node cj1,node cj2){
    return cj1.cj>cj2.cj;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>sr[i].cj;
    }
    int k=sr[0].cj;
    int v=0;
    sort(sr,sr+n*m,cmp);
    for(int i=1;i<=m;){
        for(int j=1;j<=n;j++){
            if(sr[v].cj==k) {
                cout<<i<<" "<<j;
                return 0;
            }
            v++;
        }
        if(i<m) {
            i++;
        }else break;
        for(int j=n;j>=1;j--){
            if(sr[v].cj==k) {
                cout<<i<<" "<<j;
                return 0;
            }
            v++;
        }
        if(i==m) break;
        else i++;
    }
    return 0;
}
