#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[51451];
string er[51451];
string dp[51451];
string dps[51451];
int t;
void erj(int o,int i){
	if(o!=0){
		while(o>0){
			int g=o%2;
			o=o/2;
			char p=g+48;
			er[i]=p+er[i];
		}	
	}else{
		er[i]='0';
	}
}
string tcy(string a,string b){
	string c="";
	int p=1;
	//cout<<a.size()<<" "<<b.size()<<'\n';
	if(a.size()>b.size()){
		int ua=a.size()-b.size();
		for(int i=1;i<=ua;i++){
			b='0'+b;
		}
	}
	if(a.size()<b.size()){
		int ub=b.size()-a.size();
		for(int i=1;i<=ub;i++){
			a='0'+a;
		}
	}
	while(c.size()<a.size()){
		char zq=a[a.size()-p];
		char tc=b[b.size()-p];
		if(bool(zq!=tc)){
			c=c+'1';
		}else{
			c=c+'0';
		}
		p++;
	}
	return c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		erj(a[i],i);
		dp[i]=er[i];
	}
	erj(m,51400);
	for(int i=1;i<=n;i++){
		if(dp[i-1]==er[51400]||er[i]==er[51400]){
			t++;
		}else{
			if(i>1)
			dp[i]=tcy(er[i],dp[i-1]);
		}
	}
	cout<<t;
	return 0;
}
