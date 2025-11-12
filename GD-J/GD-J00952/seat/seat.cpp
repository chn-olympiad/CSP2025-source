#include <bits/stdc++.h>
using namespace std;
const int maxn=10*10+10;
struct Node{
    int num,id;
}z[maxn];
bool cmp(Node a,Node b){
    return a.num>b.num;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s=n*m;
    for(int i=0;i<s;i++){
        cin>>z[i].num;
        z[i].id=i;
    }sort(z,z+s,cmp);
    int seat[n][m],cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            seat[i][j]=z[cnt].id;
            cnt+=1;
            if(seat[i][j]==0){
                if(i%2==0){
                    cout<<i+1<<" "<<j+1;
                }else{
                    cout<<i+1<<" "<<(m-j);
                }
            }
        }
    }
    return 0;
}

