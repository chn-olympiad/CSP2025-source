#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int a[100],b[100][100],cnt=-1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)cin>>a[i];
    int n1=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<m;i++)
    {

        if(i%2==0){
            for(int j=0;j<n;j++){
                cnt++;
                if(a[cnt]==n1)cout<<i+1<<" "<<j+1;
                b[j][i]=a[cnt];
            }
        }else{
          for(int j=n-1;j>=0;j--){
                cnt++;
                   if(a[cnt]==n1)cout<<i+1<<" "<<j+1;
                b[j][i]=a[cnt];
            }

        }
    }

    return 0;
}
