#include<bits/stdc++.h>
using namespace std;
int a[1001000];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) {
            sum=a[i];
        }

    }
    sort(a+1,a+(n*m)+1,cmp);
    int num=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==sum){
            num=i;
            continue;
        }
    }
    int s=1;
    while(num>n){
        num-=n;
        s++;
    }
    if(s%2==1){
        cout<<s<<" "<<num<<endl;
    }
    else cout<<s<<" "<<m-num+1<<endl;
    return 0;
}
