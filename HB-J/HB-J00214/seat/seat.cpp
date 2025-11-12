#include<bits/stdc++.h>
using namespace std;
int n,m,num;
struct node{
    int b,c;
}a[105];
bool cmp(node s1,node s2){
    return s1.b>s2.b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].b;
    }
    a[1].c=1;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].c){
            num=i;
        }
    }
    int l=num/n;
    if(num%n!=0){
        l++;
    }
    int h;
    if(num%n==0){
        if(l%2==0) h=1;
        else h=n;
    }
    else{
        if(l%2==0){
            h=n-num%n+1;
        }
        else{
            h=num%n;
        }
    }
    cout<<l<<' '<<h;
    return 0;
}


