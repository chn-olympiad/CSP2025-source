#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;
const int N=100005;
int t,n,ans;
int a[N][7],b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(b,0,sizeof b);
		memset(a,0,sizeof a); 
		for(int i=1;i<=n;i++){
			int d1=0,d2=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
		}
		sort(b+1,b+n+1);
		for(int i=n;i>n/2;i--){
			ans+=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
