#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int mod=998244353;
int n,a[5005],cnt,box[5005],x;
bool vis[5005];
string s;
map<string,bool>mp; 
void dfs(int cur,int k){
	if (cur==n+1 || x==k){
		int sum=0,maxs=INT_MIN,cou=0;
		for (int i=1;i<=n;i++){
			sum+=box[i];
			maxs=max(maxs,box[i]);
			if (box[i]!=0)cou++;
			//cout<<box[i]<<' ';
		}
		//cout<<"-----"<<sum<<' '<<maxs;
		//cout<<endl;
		if (cou<3){
			return ;
		}
		
		if (sum>maxs*2){
			s="";
//			cout<<cnt<<endl;
			for (int i=1;i<=n;i++){
				s+=char(box[i]+'0');
			}
			mp[s]=true;
			//cout<<s<<endl;
			cnt=mp.size();
			cnt%=mod;
		}
		return ;
	}
	for (int i=cur;i<=n+1;i++){
		if (!vis[i]){
			box[i]=a[i];
			vis[i]=true;
			x++;
			dfs(i,k);
			box[i]=0;
			vis[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=3;i<=n;i++){
		x=0;
		dfs(1,i);
	}
	cout<<cnt;
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
*/
