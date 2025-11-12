#include<bits/stdc++.h>
using namespace std;
int const N=5e3+5;
int const P=998244353;
int n,a[N],ans;
string s1;
unordered_map<string,bool> mp;

string tostr(int v){
	int u;
	string s="";
	char a;
	while(v>0){
		u=v%10;
		v/=10;
		a=(u+'0');
		s=s+a;
	}
	return s;
}

void dfs(int j,int sum,int Max,int cnt,string s){
//	cout<<j<<" "<<sum<<" "<<Max<<" "<<cnt;
	if(sum>2*Max&&cnt>=3&& !mp[s]){
//		cout<<j<<" "<<sum<<" "<<Max<<" "<<cnt<<" "<<s;
//		cout<<" "<<ans;
//		cout<<endl;
		mp[s]=true;
		ans++;
		ans%=P;
	}
	if(j>n){
//		cout<<endl;
		return;
	}
//	cout<<endl;
	dfs(j+1,sum,Max,cnt,s);
	s+=tostr(j);
	dfs(j+1,sum+a[j],max(Max,a[j]),cnt+1,s);
} 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0,s1);
	cout<<ans%P;
	return 0;
} 
