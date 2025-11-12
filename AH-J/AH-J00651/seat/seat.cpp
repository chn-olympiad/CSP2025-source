#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int tot=n*m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+1+tot,cmp);
    int k=1,c=1,l=1;
    while(x!=a[k]){
        if(c>=1&&c<n&&l%2==1){
            c++;
        }
        else if(c==n&&l%2==1){
            l++;
        }
        else if(c<=n&&c>1&&l%2==0){
            c--;
        }
        else if(c==1&&l%2==0){
            l++;
        }
        k++;
    }
    cout<<l<<" "<<c;
    return 0;
}
