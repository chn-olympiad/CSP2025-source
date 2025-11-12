#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int cnt=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
        int t;
        cin>>t;
        if(t){
            cnt++;
        }
	}
	if(n==0){
        cout<<m-cnt;
	}else{
        cout<<cnt;
	}
	return 0;
}
