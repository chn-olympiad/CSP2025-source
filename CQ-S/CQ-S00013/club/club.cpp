#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans;
int a[N][5],b[N];
int s1,s2,s3;
void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(s1<n/2){
		s1++;
		dfs(x+1,sum+a[x][1]);
		s1--;
	}
	if(s2<n/2){
		s2++;
		dfs(x+1,sum+a[x][2]);
		s2--;
	}
	if(s3<n/2){
		s3++;
		dfs(x+1,sum+a[x][3]);
		s3--;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		s1=0,s2=0,s3=0;
		int flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0) flag1=0;
			if(a[i][3]!=0) flag2=0;
		}
		if(flag1){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}else{
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
