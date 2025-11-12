#include<bits/stdc++.h>
using namespace std;
int n,m,a[105]={0},a1,an,grade;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>an;
            if(i==0&&j==0)a1=an;
            a[an]++;
        }
    }
    for(int i=100;i>=a1;i--){
        grade+=a[i];
    }
    if(grade/n%2==0)cout<<grade/n+1<<" "<<grade-grade/n*n;
    else cout<<grade/n+1<<" "<<n-grade%n+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}