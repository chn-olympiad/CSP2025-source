#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int b1,b2,b3,ans;
void dfs(int x,int n,int a1,int a2,int a3){
	if(x==n+1){
		ans=max(ans,b1+b2+b3);
		return ;
	}
	if(a1==n/2){
		if(a2==n/2){
			b3+=c[x];x++;a3++;
			dfs(x,n,a1,a2,a3);
			b3-=c[x];x--;a3--;
		}
		b2+=b[x];x++;a2++;
		dfs(x,n,a1,a2,a3);	
		b2-=b[x];x--;a2--;
	}
	else{
		b1+=a[x];x++;a1++;
		dfs(x,n,a1,a2,a3);
		b1-=a[x];x--;a1--;
	}
	b1=0,b2=0,b3=0;
	if(a2==n/2){
		if(a3==n/2){
			b1+=a[x];x++;a1++;
			dfs(x,n,a1,a2,a3);
			b1-=a[x];x--;a1--;
		}
		b3+=c[x];x++;a3++;
		dfs(x,n,a1,a2,a3);
		b3-=c[x];x--;a3--;
	}
	else{
		b2+=b[x];x++;a2++;
		dfs(x,n,a1,a2,a3);	
		b2-=b[x];x--;a2--;
	}
	b1=0,b2=0,b3=0;
	if(a3==n/2){
		if(a2==n/2){
			b1+=a[x];x++;a1++;
			dfs(x,n,a1,a2,a3);
			b1-=a[x];x--;a1--;
		}
		b2+=b[x];x++;a2++;
		dfs(x,n,a1,a2,a3);	
		b2-=b[x];x--;a2--;
	}
	else{
		b3+=c[x];x++;a3++;
		dfs(x,n,a1,a2,a3);
		b3-=c[x];x--;a3--;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,bn=0,cn=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0)bn++;
			if(c[i]==0)cn++;
		}
		if(bn==n&&cn==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans;
			exit(0);
		}
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]&&cnt1<n/2){
				b1+=a[i];cnt1++;
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]&&cnt2<n/2){
				b2+=b[i];cnt2++;
			}
			else if(c[i]>=a[i]&&c[i]>=b[i]&&cnt3<n/2){
				b3+=c[i];cnt3++;
			}
		}
		ans=max(ans,b1+b2+b3);
		b1=0,b2=0,b3=0;
		
		dfs(1,n,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 

