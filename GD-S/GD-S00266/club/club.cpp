#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100005][5],x[100005],y[100005],z[100005],used[100005];
int ans=0;
bool cmp1(int i,int j){
	return a[i][1]>a[j][1];
}
bool cmp2(int i,int j){
	return a[i][2]>a[j][2];
}
bool cmp3(int i,int j){
	return a[i][3]>a[j][3];
}
void dfs(int s1,int s2,int s3,int sum,int i){
	if(i>n){
		ans=max(ans,sum);
		return ;
	}
	if(s1+1<=n/2)dfs(s1+1,s2,s3,sum+a[i][1],i+1);
	if(s2+1<=n/2)dfs(s1,s2+1,s3,sum+a[i][2],i+1);
	if(s3+1<=n/2)dfs(s1,s2,s3+1,sum+a[i][3],i+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}		
		ans=0;
		if(n>=30){
			memset(used,0,sizeof(used));
			for(int i=1;i<=n;i++)x[i]=y[i]=z[i]=i;
			sort(x+1,x+1+n,cmp1);
			sort(y+1,y+1+n,cmp2);
			sort(z+1,z+1+n,cmp3);
			int i,j,k;
			int s1,s2,s3;
			i=j=k=1;s1=s2=s3=0;
			while(!(i>n&&j>n&&k>n)){
				while(used[x[i]]==1)i++;
				while(used[y[j]]==1)j++;
				while(used[z[k]]==1)k++;
				if(a[x[i]][1]>=a[y[j]][2]&&a[x[i]][1]>=a[z[k]][3]&&s1+1<=n/2&&i<=n){
					used[x[i]]=1;
					ans+=a[x[i]][1];
					i++;
					s1++;
				}
				else if(a[y[j]][2]>=a[x[i]][1]&&a[y[j]][2]>=a[z[k]][3]&&s2+1<=n/2&&j<=n){
					used[y[j]]=1;
					ans+=a[y[j]][2];
					j++;
					s2++;
				}
				else if(s3+1<=n/2&&k<=n){
					used[z[k]]=1;
					ans+=a[z[k]][3];
					k++;
					s3++;
				}
			}
		}
		else dfs(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}
