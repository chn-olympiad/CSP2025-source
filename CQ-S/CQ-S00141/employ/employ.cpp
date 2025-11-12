#include <bits/stdc++.h>
using namespace std;
int r[1000];
bool flg[1000005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,l;
	cin>>n>>m;
	l=n;
	string a;
	cin>>a;
	int fang=0;
	for(int i=0;i<n;i++){
		cin>>r[i];
		if(r[i]==0) {
			l--;
		}
	}
	long long num=1;
	for(int i=m;i<=l;i++){
		num*=i;
		num%=998244353;
	}
	
	cout<<num;
	return 0;
} 
