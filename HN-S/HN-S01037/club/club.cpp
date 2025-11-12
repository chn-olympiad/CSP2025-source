#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,zd,a,s[N];
bool cmp(int x,int y){
	return x>y;
}
signed lsh(){
	cin>>n;
	zd=n/2;
	for(int i;i<=n;i++){
		cin>>a;
		if(a!=0)s[i]=a;
	}
	sort(s+1,s+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=zd;i++){
		cnt+=s[i];
	}
	cout<<cnt;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)lsh();
	return 0;
}
