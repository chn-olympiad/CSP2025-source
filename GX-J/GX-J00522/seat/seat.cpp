#include<bits/stdc++.h>
using namespace std;
int s[40][40];
int j=1,l,i,n,m,r;
int num[1000];
bool cmp(int a,int b){
    return a>=b;
}
void seat(int n){
    if(j%2==1){
        for(i=1;i<=m;i++){
        s[i][j]=num[l];
        if(s[i][j]==r){
            cout<<j<<" "<<i<<endl;
            break;
        }
        l++;
    }
    }else{
        for(i=m;i>=1;i--){
        s[i][j]=num[l];
        if(s[i][j]==r){
            cout<<j<<" "<<i<<endl;
            break;
        }
        l++;
    }
}
if(j<=n&&s[i][j]!=r){
        j++;
       seat(n);
    }
    return;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int nm=n*m;
    for(int i=0;i<=nm-1;i++){
        cin>>num[i];
        if(i==0){
            r=num[i];
        }
    }
    sort(num,num+nm,cmp);
    seat(n);
    return 0;
}
