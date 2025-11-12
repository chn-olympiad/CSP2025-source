#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],num[5],ans;
void dfs(int pos,int sum){
	if(pos==n+1){
		ans=max(ans,sum);
	}for(int i=1;i<=3;i++){
		if(num[i]<n/2){
			num[i]++;
			dfs(pos+1,sum+a[pos][i]);
			num[i]--;
		}
	}
}void dfsb(int pos,int sum){
	if(pos==n+1){
		ans=max(ans,sum);
	}for(int i=2;i<=3;i++){
		if(num[i]<n/2){
			num[i]++;
			dfs(pos+1,sum+a[pos][i]);
			num[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		bool fa=false,fb=false;
		int b[100005];
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
			if(a[i][3]!=0){
				fa=fb=true;
			}if(a[i][2]!=0){
				fa=true;
			}
		}ans=0;
		num[1]=num[2]=num[3]=0;
		if(!fb){
			if(!fa){
				sort(b+1,b+n+1);
				for(int i=n/2+1;i<=n;i++){
					ans+=b[i];
				}
			}else{
				dfsb(1,0);
			}
		}else{
			dfs(1,0);
		}cout<<ans<<endl;
	}
	return 0;
}
