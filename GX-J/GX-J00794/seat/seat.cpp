#include<bits/stdc++.h>
#define ld long long
#define llf long double
using namespace std;
int n,m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n*m);
    for(int i=0;i<n*m;i++) cin>>a[i];
    int num=a[0],f;
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n*m;i++)
    if(a[i]==num){
        f=i;
        break;
    }
    int c=1,r=1;
    for(int k=0;k<f;k++){
        r+=pow(-1,c+1);
        if((r==1||r==n)&&k+1<f){
            c++;
            k++;
        }
    }
    printf("%d %d",c,r);
    return 0;
}

