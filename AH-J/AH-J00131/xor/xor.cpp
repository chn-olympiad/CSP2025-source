#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n0,n1;
int n,m,sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            n1++;
        }
        if(a[i]==0){
            n0++;
        }
    }
    if(m==1){
        cout<<n1;
    }
    else{
        int k=1;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]&&a[i]==1&&k==1){
                k=0;
                sum++;
            }
            else{
                if(a[i]==0){
                    k=0;
                }
                if(a[i]==1){
                    k=1;
                }
            }

        }
        cout<<sum+n0;
    }
	return 0;
}
