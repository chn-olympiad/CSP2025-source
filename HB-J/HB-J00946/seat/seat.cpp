#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
        ans=a[1];
	}
	sort(a+1,a+1+n*m);
	long long cnt=n*m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2==0){
                if(j==1) j=n+2;
                if(j==1) break;
                j-=2;
            }
            if(ans==a[cnt]) cout<<i<<" "<<j;
            cnt--;
        }
    }
	return 0;
}
