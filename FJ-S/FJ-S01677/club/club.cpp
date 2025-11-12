#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
struct node{
	int c1,c2,c3;
}a[100001];
int T,n,ans,max1,p1,p2,p3;
void dfs(int x){
	if(x>n){
		ans=max(ans,max1);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1 && p1+1<=n/2){
			max1+=a[x].c1;
			p1++;
			dfs(x+1);
			max1-=a[x].c1;
			p1--;
		}
		else if(i==2 && p2+1<=n/2){
			max1+=a[x].c2;
			p2++;
			dfs(x+1);
			max1-=a[x].c2;
			p2--;
		}
		else if(i==3 && p3+1<=n/2){
			max1+=a[x].c3;
			p3++;
			dfs(x+1);
			max1-=a[x].c3;
			p3--;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].c1>>a[i].c2>>a[i].c3;
		ans=0;max1=0;p1=0;p2=0;p3=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
