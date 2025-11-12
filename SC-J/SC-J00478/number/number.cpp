#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int m=0;
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[m]=s[i]-'0';
			m++;
		}
	}
	sort(a,a+m);
	for(int i=m-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}