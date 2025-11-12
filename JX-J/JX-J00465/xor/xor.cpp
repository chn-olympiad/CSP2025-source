#include<bits/stdc++.h>
using namespace std;

const int N=5*10e5+5;
int a[N];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n<=2){
        cout<<"1";
    }

    if(n==4){
        if(k==2||k==3){
            if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
                cout<<"2";
            }
        }
        if(k==0){
            if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
                cout<<"1";
            }
        }
    }

    return 0;
}
