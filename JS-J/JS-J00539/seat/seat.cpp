#include <bits/stdc++.h>
using namespace std;
int a[105];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    int stdnum=n*m;

    for(int i=1;i<=stdnum;i++){
        cin>>a[i];
    }

    int Rsc=a[1];

    for(int i=1;i<=stdnum;i++){
        for(int j=i;j<=stdnum;j++){
            if(a[i]<a[j]){
                int c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
    }

    //for(int i=1;i<=stdnum;i++) cout<<a[i]<<' ';

    for(int i=1;i<=stdnum;i++){
        if(a[i]==Rsc){
            //cout<<i<<" ";
            int mo=i%n;
            if(mo==0) mo=n;
            int chu=(i-1)/n;
            cout<<chu+1<<' '<<((chu%2==0)?(mo):(n-mo+1));
            break;
        }
    }

    return 0;
}
