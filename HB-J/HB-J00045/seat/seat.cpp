#include<bits/stdc++.h>
using namespace std;
struct abc{
    int text,id;
}a[105];
bool cmp(abc x,abc y){
    return x.text>y.text;
}
int n,m,s,ansn,ansm;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].text;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i].id==1){
            s=i;
            break;
        }
    if(s%m!=0)
        ansn=floor(s/(m*1.0))+1;
    else 
        ansn=s/m;
    if(ansn%2==0){
        if(s%m==0)
            ansm=1;
        else
            ansm=m-s%m+1;
    }
    else{
        if(s%m==0)
            ansm=m;
        else
            ansm=s%m;
    }
    cout<<ansn<<" "<<ansm;
    return 0;
}
