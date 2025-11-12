#include <bits/stdc++.h>
using namespace std;

int t,n,x[100000+10],y[100000+10],z[100000+10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		long long s=0;
		for(int i=1;i<=n;i++){
			cin >> x[i] >> y[i] >> z[i];
			s+=x[i]+y[i]+z[i];
		}
		cout << s << endl;
	}
																																																																																																																																																											
	return 0;
}
