#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N][4],b[N];
int T;
bool A(int n){
	for(int i=1;i<=n;i++){
		if(a[i][2]||a[i][3]) return false;
	}
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans,n;
		cin>>n;	
		memset(a,0,sizeof a);	
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n==2){
			int ans1=max(max(a[1][1],a[1][2]),a[1][3]),ans2=max(max(a[2][1],a[2][2]),a[2][3]);
			ans=ans1+ans2;
		}
		if(A(n)){
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--) ans+=b[i];
		}
		cout<<ans<<endl;
	}
}
