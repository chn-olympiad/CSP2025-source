#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
using ll=long long;
int n;
int a[12];
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		char c=s[i];
		a[c-'0']++;
	}
//	for(int i=0;i<=9;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(int i=9;i>=0;i--){
		int k=a[i];
		for(int j=1;j<=k;j++)cout<<i;
	}
	return 0;
} 
