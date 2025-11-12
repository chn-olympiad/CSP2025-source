#include<bits/stdc++.h>
using namespace std;
int n,m,len,tttt;
int a[1000];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    len=n*m;
    for(int i=1;i<=len;i++){
        cin>>a[i];
    }
    int a1=a[1];
    sort(a+1,a+len+1,cmp);
    for(int i=1;i<=len;i++){
        if(a[i]==a1){
            tttt=i;
            break;
        }
    }//find a1 down biao
    int ansn=0,ansm=0;

    ansm=tttt/n;
    if(tttt%n!=0)ansm++;
    if(ansm%2==0){
        if(tttt%n==0){
            ansn=1;
        }
        else{
            ansn=n-(tttt%n)+1;
        }
    }else{
        if(tttt%n==0){
            ansn=n;
        }else{
            ansn=tttt%n;
        }
    }
    cout<<ansm<<' '<<ansn;
    return 0;
}
