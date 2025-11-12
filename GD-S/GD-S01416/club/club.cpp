#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n,sum,sumx[4],ans;
struct student{
	int a[4];
}s[100];

void dfs(int x){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if((sumx[i]+1)*2>n) continue;
		sum+=s[x].a[i];
		sumx[i]++;
		dfs(x+1);
		sum-=s[x].a[i];
		sumx[i]--;
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
		}
		sum=0,sumx[1]=0,sumx[2]=0,sumx[3]=0,ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
