#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int answer;
int a[1007];
int g[17][17];
bool cmp(int u,int v){
    return u>v;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    answer=a[1];
    sort(a+1,a+n*m+1,cmp);
    int i=1,j=1,cnt=0;
    while( true ){
        g[i][j]=a[++cnt];
        if( a[cnt]==answer ){
            cout<<j<<" "<<i;
            break;
        }
        if( i==n&&j%2==1 || i==1&&j%2==0 ){
            j++;
        }
        else{
            if( j%2==1 ){
                i++;
            }
            else{
                i--;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
