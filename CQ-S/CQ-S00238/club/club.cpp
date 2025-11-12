#include<bits/stdc++.h>
#define int long long
using namespace std;

int T;
int n;
int a[1000010],b[1000010],c[1000010];
int ans;

void dp(int x,int y,int a1,int b1,int c1){
	if(x-1==n){
		ans=max(ans,y);
		return;
	}
	if(a1<n/2) dp(x+1,y+a[x],a1+1,b1,c1);
	if(b1<n/2) dp(x+1,y+b[x],a1,b1+1,c1);
	if(c1<n/2) dp(x+1,y+c[x],a1,b1,c1+1);
}

struct pm{
	int t,r;
}A[1000010];

bool cmp(pm x,pm y){
	return x.r>x.t;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		int a1=1,a2=1,a3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) a2=0;
			if(c[i]!=0) a3=0;
		} 
		if(a2==1){
			for(int i=1;i<=n;i++) b[i]=a[i];
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--) ans=ans+b[i];
		}
		dp(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 
