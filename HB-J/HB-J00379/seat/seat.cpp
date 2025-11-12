#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int x,y;
    cin>>x>>y;
    int a[105],b[105],num,num1,n=x*y,t=0;
    cin>>a[0];
    int a1=a[0];
    for(int i=1;i<x*y;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
		b[i]=a[t];
		t++;
    }
    for(int i=0;i<x*y;i++){
        if(b[i]==a1){
            num=i;
        }
    }
    num1=num%x;
    if((num/x)%2==0){
        cout<<(num/x)+1<<" "<<num%x+1;
        return 0;
    }else{
        cout<<(num/x)+1<<" "<<x-num1;
        return 0;
    }
    return 0;
}
