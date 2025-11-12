#include<bits/stdc++.h>
#include<string>
freopen("seat.in","r",stdin);
/reopen("seat.out","w",stdout);
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[110];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int r=a[0];
    for(int i=0;i<n*m;i++){
            for(int k=i+1;k<n*m;k++){
                if(a[k]>a[i]){
                    int max=a[k];
                    a[k]=a[i];
                    a[i]=max;
            }
        }
    }
    int x=1,y=1,ny=1;
    for(int i=0;i<n*m;i++){
        x=i/n+1;

        if(x%2==0){
            ny=n-y+1;
        }
        else
            ny=y;
        y%=n;
        y++;
        if(a[i]==r)
            cout<<x<<" "<<ny<<endl;

    }
    return 0;
}
