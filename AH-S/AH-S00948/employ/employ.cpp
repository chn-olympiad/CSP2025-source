#include<bits/stdc++.h>
using namespace std;
int a[1005];
long long int A(int C){
	int ans=1;
	for(int i=1;i<=C;i++){
		ans*=i;
	}
	return ans;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<"1";
		return 0;
	}
	int C=lower_bound(a+1,a+n+1,m)-a;
	cout<<A(C);
	return 0;
}
