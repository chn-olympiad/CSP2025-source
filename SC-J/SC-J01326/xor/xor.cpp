#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200002],num,num1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            num++;
        }
        if(a[i]==1) num1++;
    }
    if(k==1){
        if(num1) cout<<num1+1;
        else cout<<0;
        return 0;
    }
	if(num) cout<<num+1;
	else cout<<0;
}
