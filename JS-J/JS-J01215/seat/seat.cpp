#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+9;
int n,m;
int k;
int a[maxn];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    cin>>a[1];
    int cnt=1;
    for(int i=2;i<=k;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            cnt++;
        }
    }
    int l=cnt/n;
    if(cnt%n!=0){
        l++;
    }
    int h=cnt%n;
    if(h==0) h=n;
    if(l%2==0){
        h=n-h+1;
    }
    cout<<l<<" "<<h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
