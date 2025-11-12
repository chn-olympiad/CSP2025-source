#include<bits/stdc++.h>
using namespace std;
int q;
int n;
long long a[100005][10];
int m1[100005],m2[100005];
vector<int> c[10];
long long ans[10];
long long ans1;
long long com[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=3;i++) c[i].clear(),ans[i]=0;
		ans1=0;
		for(int i=1;i<=n;i++){
			int max1=-1,max2=-1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>max1) max2=max1,m2[i]=m1[i],m1[i]=j,max1=a[i][j];
				else if(a[i][j]>max2) m2[i]=j,max2=a[i][j];
			}
			c[m1[i]].push_back(i);
			ans[m1[i]]+=max1;
		}
		ans1=ans[1]+ans[2]+ans[3];
		int t=-1;
		for(int i=1;i<=3;i++){
			if((int)c[i].size()>n/2){
				t=i;
				break;
			}
		}
		if(t==-1){
			cout<<ans1<<endl;
			continue;
		}
		int tot=0;
		for(int i=0;i<(int)c[t].size();i++){
			int x=c[t][i];
			tot++;
			com[tot]=a[x][m1[x]]-a[x][m2[x]];
		}
		sort(com+1,com+1+tot);
		int id=0;
		while(tot>n/2){
			id++;
			ans1-=com[id];
			tot--;
		}
		cout<<ans1<<endl;
	}
	return 0;
}

