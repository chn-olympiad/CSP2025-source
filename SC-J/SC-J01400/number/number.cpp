#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	long long m[100000];
	long long a=0;
	cin>>n;
	for(int i=0;i<n.length();i++){
		if(n[i]-'0'<=9&&n[i]-'0'>=0){
			m[a]=n[i]-'0';
			a++;
		}
	}
	sort(m,m+a);
	for(int i=a-1;i>=0;i--){
		cout<<m[i];
	}
	return 0;
}