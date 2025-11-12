#include<bits/stdc++.h>

using namespace std;
int a[15][15];
bool cmp(int x,int y){
return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x=2,y=1,cnt=1;
    a[1][1]=cnt++;
    while(y<=m+1){
        if(x>1&&x<n){
            //shu
            if(y%2==1){
                a[x++][y]=cnt++;
            }
            else a[x--][y]=cnt++;
        }
        else if(x==n){a[x][y++]=cnt++;a[x--][y]=cnt++;}

        else if(x==1){a[x][y++]=cnt++;a[x++][y]=cnt++;}
    }
    int s=n*m;
    int book[s+10];
    for(int i=1;i<=s;i++){
        cin>>book[i];
    }
    int r=book[1];
    sort(book+1,book+s+1,cmp);
    //for(int i=1;i<=s;i++) cout<<book[i]<<' ';
    //find
    for(int i=0;i<s;i++){
        if(book[i]==r){
            r=i;
            break;
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) { if(a[i][j]==r) { cout<<j<<' '<<i; return 0;} }

    return 0;
}

