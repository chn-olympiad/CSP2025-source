#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[102];
    for(int i=0;i<n*m;i++)
    cin>>a[i];
    int x=a[0];
    sort(a,a+n,cmp);
    for(int i=0;i<m*n;i++){
        if(x==a[i]){
            x==i+1;
            break;
        }
    }
    int num=x%n;
    int sum=x/n;
    if(sum%2==1)num=n-x+1;
    sum++;
    cout<<sum<<" "<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
