#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long ans=1;
	int cnt=0;
	int p=n;
	for(int i=0;i<n;i++){
		int check;
		cin>>check;
		if(check==0){
			p--;
			cnt++;
		}
	}
	for(int i=2;i<=p;i++){
		ans*=i;
	}
	long long anss=(ans+cnt)%998244353;
	cout<<anss;
	return 0;
}
