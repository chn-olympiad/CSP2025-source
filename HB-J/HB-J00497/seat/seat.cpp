#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[10005],op=1,i,j;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    //cout<<s<<endl;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
            //cout<<a[i]<<" ";
        if(a[i]==s){
            s=i;
            break;
        }
    }
    //cout<<endl<<s<<endl;
    if(n==1){
        cout<<1<<" "<<s;
        return 0;
    }
    if(m==1){
        cout<<s<<" "<<1;
        return 0;
    }
    i=1;
    j=1;
    for(int k=2;k<=s;k++){
        if((i==1&&op==0)||(i==n&&op==1)){
            op=(1-op);
            j++;
        }
        else{
            if(op==1)i++;
            else i--;
        }
    }
    cout<<j<<" "<<i;
    return 0;
}
