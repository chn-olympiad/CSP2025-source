#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int a[N];
int main(){
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<=s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			a[i]=-a[i];
			cnt++;
		}
	}
	sort(a,a+N);
	for(int i=0;i<cnt;i++){
		cout<<-a[i];
	}
	return 0;
}