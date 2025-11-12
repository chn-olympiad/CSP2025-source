#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int nm=n*m;
    for(int i=1;i<=nm;i++)scanf(" %d",&a[i]);
    int a1=a[1];
    sort(a+1,a+nm+1,[](int x,int y){return x>y;});
    int t=1;
    for(int i=1;i<=n;i++){
        bool g=(i%2==0);
        for(int j=(g?m:1);(g?j>=1:j<=m);j+=(g?-1:1)){
            if(a[t]==a1){printf("%d %d",i,j);return 0;}
            t++;
        }
    }
    return 0;
}
