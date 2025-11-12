#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int tt=1;tt<=t;tt++){
		int n,a[102020],b[102020],c[102020],s=0,sa=0,sb=0,sc=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i] >> b[i] >> c[i];
			sa+=a[i];sb+=b[i];sc+=c[i];
		}
		if(sb==0&&sc==0){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--){
				s+=a[i];
			}
			cout << s << endl;
		}
		else if(sc==0){
			
		}
	}
	return 0;
}
