#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
struct node{
	int l,r;
};
int n,k,ans,t,z;
int a[MAXN],dp[MAXN][MAXN];
bool v=false;
vector<node> q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			v=true;
		}
	}
	if(v==false&&k==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j]=dp[i][j-1]^a[j];
			if(dp[i][j]==k){
				q.push_back({i,j});
			}
		}
	}
	for(int i=0;i<q.size()-1;i++){
		if(q[i].l==0&&q[i].r==0){
			continue;
		}
		for(int j=1;j<q.size();j++){
			if(q[i].l<=q[j].l&&q[i].r>=q[j].r){
				q[i]={0,0};
			}else if(q[j].l<=q[i].l&&q[j].r>=q[i].r){
				q[j]={0,0};
			}
		}
	}
	for(int i=0;i<q.size();i++){
		if(q[i].l!=0||q[i].r!=0){
			t++;
			if(t!=1){
				break;
			}
		}
	}
	if(t==1){
		cout<<1;
		return 0;
	}
	for(int i=0;i<q.size()-1;i=z){
		while(q[i].l==0&&q[i].r==0){
			i++;
		}
		for(int j=i+1;j<q.size();j++){
		    while(q[j].l==0&&q[j].r==0){
				j++;
				if(j==q.size()){
					cout<<ans;
					return 0;
				}
			}
			if((q[i].l>=q[j].l&&q[i].l<=q[j].r)||(q[i].r>=q[j].l&&q[i].r<=q[j].r)){
				ans++;
			}else{
				ans+=2;
			}
			z=j;
		}
	}
	cout<<ans;
	return 0;
}
