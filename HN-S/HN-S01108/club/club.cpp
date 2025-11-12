#include<bits/stdc++.h>
using namespace std;
int a[100010][4];
int n,maxcnt;
int ans;
int f[4];
void dfs(int depth,int sum,int z){
	if(depth==n){
		if(sum>ans)ans=sum;
		return;
	}
	for(int j=1;j<=3;j++){
		if(f[j]+1<=maxcnt){
			f[j]++;
			//cout<<"i and j:"<<" "<<i<<" "<<j<<endl;
			dfs(depth+1,sum+a[z][j],z+1);
			f[j]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		bool flagb=true,flagc=true;
		cin>>n;
		ans=0;
		maxcnt=n/2;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2&&a[i][j]!=0)flagb=false;
				if(j==3&&a[i][j]!=0)flagc=false;
			}
		if(n<=30){
			dfs(0,0,1);
			cout<<ans<<endl;
		}
		else if(flagb&&flagc){
			vector<int>v;
			for(int i=1;i<=n;i++)
				v.push_back(a[i][1]);
			sort(v.begin(),v.end());
			for(int i=v.size()-1;i>=v.size()-maxcnt;i--)ans+=v[i];
			cout<<ans<<endl;
		}
		else if(flagc){
			int lf=n,ri=0;
			vector<int>va;
			for(int i=1;i<=n;i++){
				ans+=a[i][1];
				va.push_back(a[i][2]-a[i][1]);
			}
			sort(va.begin(),va.end());
			for(int i=va.size()-1;i>=va.size()-n/2;i--)ans+=va[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
