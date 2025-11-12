#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+86;
long long T,n,a1,a2,a3,maxn = -2e9,ans;
long long a[N],b[N],s[N];

int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	
	cin>>T;
	while (T--){
		cin>>n;
		
		for (int i = 1;i <= n;i++){
			cin>>a1>>a2>>a3;
			a[1] = a1;
			a[2] = a2;
			a[3] = a3;
			if (a1 < a2){
				swap(a1,a2);
			}
			if (a1 < a3){
				swap(a1,a3);
			} 
			if (a2 < a3){
				swap(a2,a3);
			}
			b[i] += a1;
			for (int i = 1;i <= 3;i++){
				if (a[i] == a1 and s[i]+a1 <= n/2){
					s[i] += a1;
				}else if(a[i] == a1 and s[i]+a1 > n/2){
					s[i+1] += a1;
				}
			}
		}
		
		for (int i = 1;i <= n;i++){
			ans += b[i]; 
		}
		cout<<ans<<" ";
	}
	/*text one
	1
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	
	text two
	1 4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	
	text three
	1 2
	10 9 8
	4 0 0
	*/
	return 0;
} 
