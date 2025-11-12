#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=1;i<=n;i++){
		if(s>="1"&&s<="9"){
			cin>>a[i];
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cout<<a[i];	
	}
	return 0;
}
