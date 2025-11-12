#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1e4+10;
int a[maxn];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++){
        cin>>a[i];
    }
    int p=a[1];
    int place=0;
    sort(a,a+1+s);
    for(int i=s;i>=1;i--){
        place++;
        if(a[i]==p){
            break;
        }
    }
    int l=(place-1)/n+1;
    int h=place-((place-1)/n)*n;
    if(l%2==0){
        h=n-h+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
