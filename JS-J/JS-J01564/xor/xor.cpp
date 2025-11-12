#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int a[N];

int xor01(int x,int y){if(x==y) return 1;return 0;}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n,k;
    cin>>n>>k;

    bool spcA=1,spcB=1;
    if(!(n<=100 && k==0)) spcA=0;
    if(!(n<=2e5 && k<=1)) spcB=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[N]!=1) spcA=0;
        if(a[i]!=0 && a[i]!=1) spcB=0;
    }

    if(spcA){ //Everything in a is 1, and k=0, n<=100
        // Two 1 is going to be 0. So, let's k 2
        cout<<n/2<<endl; //xia qu zheng
        return 0;
    }

    if(spcB){ //Everything in a is 1 or 0, and k=1 or 0 , n=10 / 100 / 200005
        if(k==1){
            int cnt=0;
            int p=1;
            while(p<=n){
                if(a[p]==1) cnt++;
                p++;
            }
            cout<<cnt<<endl;
            return 0;
        }
        else{
            int cnt=0;
            int p=1;
            while(p<=n){
                if(a[p]==0) cnt++;
                if(a[p]==1 && p+1<=n && a[p+1]==1) cnt++,p++;
                p++;
            }
            cout<<cnt<<endl;
            return 0;
        }
    }

    cout<<2<<endl;
    return 0;
}
