#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],b,o;
bool cmp(int a,int b){
    if(a>b) return true;
    else return false;
}
int main(){
    freopen("seat.in","r",stdin);        freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>a[i];
    b=a[1];
    sort(a+1,a+1+n*m,cmp);
    for (int i=1;i<=n*m;i++){
        if (a[i]==b){
            o=i;
            break;
        }
    }
    cout<<((o-1)/n)+1<<' ';
    if (((o-1)/n)%2==1) cout<<n-((o-1)%n);
    else cout<<((o-1)%n)+1;
    fclose(stdin);      fclose(stdout);
    return 0;
}