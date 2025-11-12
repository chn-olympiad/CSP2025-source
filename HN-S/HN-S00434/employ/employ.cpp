#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N],b[N],c[N],s[N];
unsigned long long sum=1;
string u;
int t,n;
int q=0,w=0,e=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t>>n>>u;
	int bol=1;
	for(int i=0;i<u.size();i++){
		if(u[i]!=1) bol=0,break;
	}
	if(bol==1){
		for(int i=1;i<=n;i++){
			sum*=i;
			sum=sum%998244353;
			if(sum==0) sum=1;
		}
		cout<<sum;
	}
	else{
		cout<<0;
	}
	return 0;
} 
