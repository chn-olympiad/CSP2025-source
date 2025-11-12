#include<bits/stdc++.h>
using namespace std;
string tentotwo(int ten){
	if(ten==0)return "";
	return tentotwo(ten/2)+(char)(ten%2+'0');
}
string stringwithzero(string two){
	int s=two.size();
	for(int i=0;i<(20-s);i++)two='0'+two;
	return two;
}
string xo(string a,string b){
	string c;
	for(int i=0;i<20;i++)c+=(char)('0'+(a[i]!=b[i]));
	return c;
}
int n,ki;
string k;
string a[500005]={"00000000000000000000"};
int dp[500005];
int dfs(int i){
	int c=0;
	string j=a[0];
	for(;i<= n;i++){
		j=xo(j,a[i]);
		if(j==k){
			if(dp[i+1]!=0){
				c+=dp[i+1];
				c+=1;
				return c;
			}
			c++;
			j=a[0];
		}
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>ki;
    k=stringwithzero(tentotwo(ki));
    int t;
    for(int i=1;i<=n;i++){
		cin>>t;
		a[i]=stringwithzero(tentotwo(t));
	}
	for(int i=n;i>0;i--){
		dp[i]=max(dfs(i),dp[i+1]);
	}
	cout<<dp[1];
	return 0;
}
