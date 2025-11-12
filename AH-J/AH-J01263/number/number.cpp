#include <bits/stdc++.h>

using namespace std;
int a[10000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n,lt=0;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[lt]=s[i]-'0';
			lt++;
		}
			
	}
	sort(a,a+lt);
	for(int i=lt-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
