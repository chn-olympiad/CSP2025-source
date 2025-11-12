#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long a=1;
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int l =s.size();
	int p;
	int ls=n;
	for(int i = 0;i<n;i++){
		cin>>p;
		if(p == 0){
			ls--;
		}
	}
	if(l>=ls){
		for(int i = ls;i>=1;i--){
			a*=i;
			if(a>=998244353){
				while(a>=998244353){
					a-=998244353;
				}
			}
		}
		cout<<a;
	}
	else{
		for(int i = ls;i>=min(ls-l+1,ls-m+1);i--){
			a*=i;
			if(a>=998244353){
				while(a>=998244353){
					a-=998244353;
				}
			}
		}
		cout<<a;	
	}
	return 0; 
}
