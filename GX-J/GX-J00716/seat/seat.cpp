#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    if(a<b){
        return b<a;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s[1000]={};
    int a,x,y,num=0;
    for(int i=0;i<n*m;i++){
        cin>>s[i];
        if(i==0){
            a=s[i];
        }
    }
    sort(s,s+m*n,cmp);
    for(int i=0;i<n*m;i++){
        if(a==s[i]){
            num=i+1;
        }
    }
    if(num%2){
        x=num/n+1;
    }else{
        x=num/n;
    }
    if(x%2==1){
        y=num%((x-1)*m);
    }else{
        y=num%m+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
