#include<bits/stdc++.h>
using namespace std;
int a,b,c[10005];
bool cmp(int a,int b){
return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>c[i];
    }
    int num=c[1];
    sort(c+1,c+1+a*b,cmp);
    int sum;
    for(int i=1;i<=a*b;i++){
        if(c[i]==num){
            sum=i;
            break;
        }
    }
    if(sum%a==0){
        cout<<sum/a<<' '<<b;
    }
    else{
            if((sum/a+1)%2==1){
                cout<<sum/a+1<<' '<<sum%a;
            }
        else{
            cout<<sum/a+1<<' '<<b-sum%a+1;
        }
    }
    return 0;
}
