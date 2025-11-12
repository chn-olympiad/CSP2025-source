#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100005];
int b[100005];
int c[100005];
int d[100005];
int A,B,C; 
int len;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int ans=0;
	A=B=C=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=b[i] && a[i]>=c[i]){
			ans+=a[i];
			A++;
		}else if(b[i]>=a[i] && b[i]>=c[i]){
			ans+=b[i];
			B++;
		}else{
			ans+=c[i];
			C++;
		}
	}
	int t=n/2;
	len=0;
	if(A>t){
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i] && a[i]>=c[i]){
				d[++len]=a[i]-max(b[i],c[i]);
			}
		}
		sort(d+1,d+1+len);
		int cnt=A-t;
		for(int i=1;i<=cnt;i++){
			ans-=d[i];
		}
	}else if(B>t){
		for(int i=1;i<=n;i++){
			if(b[i]>=a[i] && b[i]>=c[i]){
				d[++len]=b[i]-max(a[i],c[i]);
			}
		}
		sort(d+1,d+1+len);
		int cnt=B-t;
		for(int i=1;i<=cnt;i++){
			ans-=d[i];
		}
	}else if(C>t){
		for(int i=1;i<=n;i++){
			if(c[i]>=a[i] && c[i]>=b[i]){
				d[++len]=c[i]-max(a[i],b[i]);
			}
		}
		sort(d+1,d+1+len);
		int cnt=C-t;
		for(int i=1;i<=cnt;i++){
			ans-=d[i];
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}
