#include<bits/stdc++.h>
using namespace std;

int n,k,s1=0,s2=0,cnt=0;
int a[500001];
bool used[500001]={0};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            s1++;
        }
        if(a[i]==0){
            s2++;
        }
    }
    if(s1==n){
        if(k==0){
            if(n==1){
                cout<<0;
            }
            else if(n==2){
                cout<<1;
            }
            else{
                cout<<s1/2;
            }
        }
    }
    else if(s1+s2==n&&s2!=0){
        if(k==0){
            cout<<s1/2+s2;
        }
        else if(k==1){
           cout<<s1;
        }
    }
    return 0;
}
