#include<bits/stdc++.h>
using namespace std;
long long n,q=1,w[5000];
vector<int>a;
bool book[101];
void dfs(int k,int x){
	int b=0,c=0;
	for(int i=0;i<a.size();i++){
		b+=a[i];
		c=max(c,a[i]);
	}
	if(b-c>c){
		q=(q+1)%998244353;
	}
	if(k==n){
		return;
	}
	for(int i=x;i<n;i++){
		if(book[i]==false){
			book[i]=true;
			a.push_back(w[i]);
			dfs(k+1,i);
			a.pop_back();
			book[i]=false;
		}
	}
}
long long jc(int a){
	long long b=1;
	for(int i=1;i<=a;i++){
		b=(b*i)%998244353;
	}
	return b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int s=0;
	bool d=true;
	long long b=0;
	for(int i=0;i<n;i++){
		cin>>w[i];
		if(w[i]==1&&d){
			s++;
		}
		if(w[i]>1){
			d=false;
		}
	} 
	if(d){
		int f=0,g=jc(s);
		for(int i=3;i<=s;i++){
			f=(f+g/jc(i)/jc(s-i))%998244353;
		}
		cout<<f;
		return 0;
	}
	dfs(1,0);
	cout<<q;
	return 0;
}
