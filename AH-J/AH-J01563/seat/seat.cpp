#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            r=i;
        }
    }
    //cout<<r<<endl;
    int lie=r/n+1,yu=r%n,hang=0;
    if(r%n==0){
        lie=r/n;
        yu=n;
    }
    if(lie%2==1){
        hang=yu;
    }else{
        hang=n-yu+1;
    }
    cout<<lie<<" "<<hang;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
