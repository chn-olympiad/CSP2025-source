#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re return
#define sz 10000005
#define ew 5005
#define sscc cout<<6;
int sum;
int half;
int n;
struct node{
	int x,y,z;
}a[sz];
void dfs(int y,int on,int tw,int th,int num){
	if(y>n){
		re ;
	}
	if(on>half){
		re ;
	}
	if(tw>half){
		re ;
	}
	if(th>half){
		re ;
	}
	sum=max(sum,num);
	dfs(y+1,on+1,tw,th,num+a[y+1].x);
	dfs(y+1,on,tw+1,th,num+a[y+1].y);
	dfs(y+1,on,tw,th+1,num+a[y+1].z);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		half=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sum=0;
		dfs(0,0,0,0,0);
		cout<<sum<<endl;
	}
	re 0;
}
