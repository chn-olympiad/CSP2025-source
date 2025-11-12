#include<bits/stdc++.h>
using namespace std;
bool cmp(int i,int j){
    return i>j;
}
int n,m,a[105],ch=1,cl=1,an;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    an=a[0];
    sort(a,a+n*m,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2==0){
                for(int k=(i-1)*n+1;k<=((i-1)*n+1+n)/2;k++){
                    swap(a[k],a[n+k-1]);
                }
            }
            if(a[i*j]==an){
                cout<<i<<' '<<j;
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

