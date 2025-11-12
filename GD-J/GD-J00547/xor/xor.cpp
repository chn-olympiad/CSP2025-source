#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void fropen(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
#define int long long
const int N=5e5;
int a[N+10],s[N+10];
signed main(){
	//How can I cheat for score?
	//40pts!
	fropen("xor");
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	int cnt=0;
	for(int l=1;l<=n;l++){
		bool flag=false;
		int r=l;
		for(;r<=n;r++){
			if((s[r]^s[l-1])==k){
				cnt++;
				flag=true;
				break;
			}
		}
		if(flag){
			l=r;
		}
	}
	cout<<cnt;
	return 0;
}
