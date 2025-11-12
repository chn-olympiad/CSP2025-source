#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a[1000];
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>=0&&s[i]<=9){
			a[i]=s[i];
		}
	}
	for(int i=0;i<=s.size();i++){
		cout<<a[i];
	}
	return 0;
}