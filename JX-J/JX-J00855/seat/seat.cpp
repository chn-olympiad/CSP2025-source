#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        scanf("%d",&a[i]);
    }
    int t=a[1],i,j,cnt;
    i=j=cnt=1;
    sort(a+1,a+sum+1,cmp);
    while(j<=m){
        while(i<=n){
            if(a[cnt]==t){
                cout<<j<<" "<<i;
                return 0;
            }
            i++;
            cnt++;
        }
        j++;
        i--;
        while(i>=1){
            if(a[cnt]==t){
                cout<<j<<" "<<i;
                return 0;
            }
            i--;
            cnt++;
        }
        i++;
        j++;
    }
    cout<<j<<" "<<i;
    return 0;
}
