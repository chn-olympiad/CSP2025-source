#include<bits/stdc++.h>
using namespace std;

int n,m;
int flag,ind;
int a[105];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    flag=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==flag){
            ind=i;
            break;
        }
    }
    int col,line;
    col=ind/n+1;
    if(col%2==0){
        line=n-ind%n;
    }
    else{
        int pre_line=(ind+1)%n;
        if(col%2==0){
            if(pre_line==0){
                line=1;
            }
            else{
                line=n-(pre_line-1);
            }
        }
        else{
            if(pre_line==0){
                line=n;
            }
            else{
                line=pre_line;
            }
        }
    }
    cout<<col<<" "<<line<<endl;
    return 0;
}
