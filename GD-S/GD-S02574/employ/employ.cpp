#include<bits/stdc++.h>
#define modd 998244353
using namespace std;

int n,m;
int sum=1;
int t;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		if(!c)t++;
	}
	if(n-t<m){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=modd;
	}
	cout<<sum;
	return 0;
}
