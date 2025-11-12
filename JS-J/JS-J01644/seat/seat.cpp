#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[110],temp;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>a[i];
    temp=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for (int i=1;i<=n*m;i++){
        if (a[i]==temp){
			//cout<<i<<" ";
			int j=i;
            int col=(j/(2*n))*2;
            if (j%(2*n)==0){
				if (n%2==0){
					cout<<col<<" "<<1<<endl;
				}
			}else{
				j%=2*n;
				if (j<=n){
					cout<<col+1<<" "<<j<<endl;
				}else{
					cout<<col+2<<" "<<2*n-j+1<<endl;
				}
			
			}
			break;
        }
    }
    return 0;
}
