#include<bits/stdc++.h>
using namespace std;
int q;
int a[100010][3];
int d[100010];
int mx[100010];
int ans,cnt;
int f[3];

void dfs(int c,int n){
	if(c>n){
		ans=max(cnt,ans);
		return;
	}
	int cnt1=cnt;
	for(int i=c;i<=n;i++){
		cnt1+=mx[i]; 
	}
	if(cnt1<ans){
		return;
	}
	for(int i=0;i<=2;i++){
		if(f[i]<n/2){
			d[c]=i;
			f[i]++;
			cnt+=a[c][i];
			dfs(c+1,n);
			cnt-=a[c][i];
			f[i]--;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	int n;
	while(q--){
		cin>>n;
		f[0]=0;
		f[1]=0;
		f[2]=0;
		ans=INT_MIN;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2]; 
			mx[i]=max(a[i][2],max(a[i][0],a[i][1]));
		}
		dfs(1,n);
		cout<<ans<<endl;
	}
	return 0;
}