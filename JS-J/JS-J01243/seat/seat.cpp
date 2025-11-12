#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,x,number;
int a[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    x=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==x){
            number=i;
        }
    }
    int ans1=number/n+1;
    int ans2=0;
    if(ans1%2==1){
        ans2=(number%n)+1;
    }
    else{
        ans2=n-(number%n);
    }
    cout<<ans1<<" "<<ans2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
