#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][5],b[N],ans[5],x=0,y=0,s1=0,s2=0,s3=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3]){
				b[i]=1;
				s1++;
			}
			else if(a[i][2] > a[i][1] && a[i][2] > a[i][3]) {
				b[i]=2;
				s2++;
			}
			else if(a[i][1]==a[i][2] && s1-1<s2 && s1+1<=n/2){
				b[i]=1;
				s1++;
				continue;
			}
			else if(a[i][1]==a[i][2] && s1>s2-1 && s2+1<=n/2){
				b[i]=2;
				s2++;
				continue;
			}
		}
		if (n==2){
			int i=1;
			ans[b[i]]+=a[i][b[i]];
			cout << ans[1]+ans[2];
		}
	}
	return 0;
}
