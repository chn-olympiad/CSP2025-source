#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500010],ans;
int st1[500010],st2[500010],tp1,tp2;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	st1[++tp1]=0;
	for(int i=1;i<=n;i++) {
		bool tf=0;
		for(int j=1;j<=tp1;j++) {
			st2[++tp2]=st1[j]^a[i];
			if(st2[tp2]==k) tf=1;
		}
		tp1=tp2+1;
		for(int j=2;j<=tp1;j++) st1[j]=st2[j-1];
		tp2=0;
		if(tf) {
			ans++;
			tp1=1;
		}
	}			
	cout<<ans;		
	return 0;
} 
