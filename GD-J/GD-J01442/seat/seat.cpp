#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll a[1005],b[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout );
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(b[i]==a[1]){
			int hang=i/m;
			int lie;
			if(hang%2==1){
				lie=i%m;
				if(lie==0)lie=m;
			}
			else{
				lie=m-i%m;
			}
			cout<<lie<<" "<<hang;
		}
	}
	return 0;
} 


