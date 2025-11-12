#include <bits/stdc++.h>
using namespace std;
int a[500010];
int n,k,ans;
string z;
string v(int a){
	string s;
	while(a>0){
		s.push_back(a%2+'0');
		a/=2;
	}
	return s;
}
void m(string x,string y){
	for(int i=1;i<=max(x.size(),y.size());i++){
		if(x[i]==y[i]){
			z.push_back(0);
		}
		else z.push_back(1);
	}
	return;
}
int main(){
	freopen("xor.in",'w',stdin);
	freopen("xor.out",'r',stdout);
	cin>>n>>k;
	string s=v(k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=0;
	while(l<=n&&r<=n){
		r++;
		if(l==r&&a[l]==k){
			ans++;	
			r++;
		}
		else{
			for(int i=r;i<=l;i++){
				m(v(a[i]),v(a[i+1]));
				if(z==s)ans++;
			}
		}
		if(r==n){
			l++;
			r=l;	
		}
	}
	cout<<ans;
	return 0;
}
