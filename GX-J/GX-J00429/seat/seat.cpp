#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
       return x<y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >>n>>m;
    int a[n*m],ans=0;
    for(int i=1;i<=n*m;i++)cin >>a[i];
    int R=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=n*m;i>=1;i--){
        if(a[i]==R){
            break;
        }
        ans++;
    }
    ans++;
    int list1=0,seat1=0;
    if(ans%n!=0){
        list1=ans/n+1;
    }else{
        list1=ans/n;
    }
    if(list1%2==0){
        seat1=n-(ans-n*(list1-1))+1;
    }else{
        seat1=ans-n*(list1-1);
    }
    cout<<list1<<" "<<seat1;
    return 0;
}
