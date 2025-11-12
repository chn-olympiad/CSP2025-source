//GZ-J00401 贵阳市花溪区同为京学附属实验学校 袁家绎
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long ans=1;
	
	while(n-m){
		ans*=n;
		n--;
		ans%=998244353;
	}
	
	cout<<ans/m;
	return 0;
} 
