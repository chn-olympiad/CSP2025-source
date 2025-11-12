#include<bits/stdc++.h>
using namespace std;
int n,m,s1;
struct node{
    int x,y,s;
}a[105];
int cmp(node a,node b){
    return a.s>b.s;
}
int main(){
    //#Shang4Shan3Ruo6Shui4
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].s;
    }
    s1=a[1].s;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[(i-1)*n+j].s==s1){
                    cout<<i<<" ";
                    cout<<j<<endl;
                    return 0;
                }
            }
        }
        else{
            for(int j=1;j<=n;j++){
                if(a[i*n-j+1].s==s1){
                    cout<<i<<" ";
                    cout<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
