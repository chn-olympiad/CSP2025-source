#include<bits/stdc++.h>
using namespace std;
long long n,m,b[505];
string a;
bool c[505];
long long aaa(long long l,long long ij,long long op){
	long long k=0;
	if(op>=m){
		k++;
	}
	for(int i=1;i<=n;i++){
		if(!c[i] && b[i]>ij){
			c[i]=1;
			k+=aaa(l+1,ij+!(a[l]-'0'),op+(a[l]-'0'));
			c[i]=0;
		}
	}
	return k;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	cout<<aaa(0,0,0);
}
