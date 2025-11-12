#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,m,a[105],o;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	o=a[1];
	sort(a+1,a+1+n*m);
	int l=1,r=1;
	for(int i=n*m;i>=1;--i){
		if(a[i]==o){
			cout<<r<<" "<<l<<endl;
			return 0;
		}
		if(r%2){
			if(l==n){
				r++;
			}else{
				l++;
			} 
		}else{
			if(l==1){
				r++;
			}else{
				l--;
			}
		}
	}
	return 0;
}
