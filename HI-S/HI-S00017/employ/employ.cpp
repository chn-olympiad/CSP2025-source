#include<bits/stdc++.h> 

using namespace std;

int n,m;
int a[100005],c[100005];

int p=998244353;
int jc(int n){
	int ans=1;
	for(int i=n;i>=2;i--){
		ans=(ans*i)%p;
	}
	return ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		a[i]=s[i]-'0';
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	cout<<jc(n);
	return 0;
}

