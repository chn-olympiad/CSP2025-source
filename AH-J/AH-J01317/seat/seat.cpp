#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[105];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>s[i];
    int a=s[1];
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
		if(s[i]==a){
			int ls=0;
			if(i%n==0) ls=(i/n);
			else ls=((i/n)+1);
			if(ls%2){
				cout<<ls<<" ";
				if(i%n) cout<<i%n;
				else cout<<n;
			}else cout<<ls<<" "<<(ls*n-i+1);
			break;
		}
	}
    cout<<"\n";
    return 0;
}
