#include <bits/stdc++.h>
using namespace std;
int n,m,c,d;
int a[105];
int b[15][15];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    c=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==1){
                b[m-1-j][i]=a[d];
                d++;
            }
            else{
                b[j][i]=a[d];
                d++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]==c)
                cout<<j+1<<" "<<i+1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}











