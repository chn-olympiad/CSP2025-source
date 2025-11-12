#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0,now=0;
    for(int i=1;i<=n;i++){
		now=a[i] xor now;
		if(now==k){
			cnt++;
			now=0;
		}
	}
	cout<<cnt<<"\n";
    return 0;
}
