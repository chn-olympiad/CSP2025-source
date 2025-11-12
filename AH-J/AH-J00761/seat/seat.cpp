#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,cnt,k;
int t[15][15];
int a[150];
bool cmp(int l,int r){
    return l>r;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt++;
            cin>>a[cnt];
        }
    }
    k=a[1];
    sort(a+1,a+1+n*m,cmp);
    cnt=0;
    int l=1,r=0;
    while(r<m){
        r++;
        if(r%2==1){
            while(l<=n){
                cnt++;
                t[l][r]=a[cnt];
                //cout<<l<<" "<<r<<" "<<cnt<<endl;
                l++;
            }
        }else{
            while(l>1){
                l--;
                cnt++;
                t[l][r]=a[cnt];
                //cout<<l<<" "<<r<<" "<<cnt<<endl;
            }
        }
    }
	
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t[i][j]==k){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
