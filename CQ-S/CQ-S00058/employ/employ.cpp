#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
long long n,m,cnt;
string s;
long long a[505],b[505];
vector<long long> v1;
bool f[505];
bool check(vector<long long> v,int nn){
	long long sum=0,sum1=0;
	for(long long i=0;i<nn;i++){
		if(sum1>=a[v[i]]){
			sum1++;
		}
		else if(s[i]=='1'){
			sum++;
		}
		else sum1++;
	}
	return sum>=m;
}
void dfs(int sum,vector<long long> v){
	if(sum==n&&check(v,sum)){
		cnt++;
		cnt%=M;
		return;
	}
	if(sum==n) return; 
	for(long long i=1;i<=n;i++){
		if(!f[i]){
			v.push_back(i);
			f[i]=true;
			dfs(sum+1,v);
			f[i]=false;
			v.pop_back();
		}
	}
	return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,v1);
	cout<<cnt;
}
