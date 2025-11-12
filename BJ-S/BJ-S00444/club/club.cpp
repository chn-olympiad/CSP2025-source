#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int t;
int n;
int a[N][5];
int box[N];
int fa[N];
ll dp[N][5];
int ans=INT_MIN;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int cur){
	if(cur==n+1){
		//for(int i=1;i<=n;i++){
			//cout<<box[i]<<" ";
		//}
		//cout<<"\n66\n";
		int aa=0,b=0,c=0,cnt=0;
		bool fl=0;
		for(int i=1;i<=n;i++){
			//int op=box[i];
			cnt=a[i][box[i]]+cnt;
			//cout<<a[i][box[i]]<<" ";
			if(box[i]==1){
				aa++;
			}else if(box[i]==2){
				b++;
			}else{
				c++;
			}
			if(aa>n/2||b>n/2||c>n/2){
				fl=1;
				break;
			}
			
		}
		//cout<<"\n";
		if(fl!=1){
			ans=max(ans,cnt);
			//cout<<cnt<<"\n";
		}
		
		return;
	}
	for(int i=1;i<=3;i++){
		box[cur]=i;
		dfs(cur+1);
	}
}
void dfs1(int cur,int a1,int b1,int c1){
	if(a1>n/2||b1>n/2||c1>n/2) return;
	if(cur==n+1){
		//for(int i=1;i<=n;i++){
			//cout<<box[i]<<" ";
		//}
		//cout<<"\n66\n";
		int cnt=0;
		//bool fl=0;
		for(int i=1;i<=n;i++){
			//int op=box[i];
			cnt=a[i][box[i]]+cnt;
			//cout<<a[i][box[i]]<<" ";
			/*if(box[i]==1){
				aa++;
			}else if(box[i]==2){
				b++;
			}else{
				c++;
			}
			if(aa>n/2||b>n/2||c>n/2){
				fl=1;
				break;
			}*/
			
		}
		//cout<<"\n";
		//if(fl!=1){
			ans=max(ans,cnt);
			//cout<<cnt<<"\n";
		//}
		
		return;
	}
	for(int i=1;i<=3;i++){
		box[cur]=i;
		if(i==1){
			dfs1(cur+1,a1+1,b1,c1);
		}
		if(i==2){
			dfs1(cur+1,a1,b1+1,c1);
		}
		if(i==3){
			dfs1(cur+1,a1,b1,c1+1);
		}
	}
}


int main(){//20
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=INT_MIN;
		cin>>n;
		bool fla=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0){
				fla=0;
			}
		}
		if(fla){
			ans=0;
			for(int i=1;i<=n;i++){
				fa[i]=a[i][1];
			}
			sort(fa+1,fa+1+n,cmp);
			/*for(int i=1;i<=n;i++){
				cout<<fa[i]<<" ";
			}*/
			for(int i=1;i<=n/2;i++){
				ans+=fa[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		
		dfs1(1,0,0,0);
		cout<<ans<<"\n";
	}
	
	return 0;
}
