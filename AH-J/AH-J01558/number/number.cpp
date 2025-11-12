#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int p=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[p++]=s[i]-'0';
		}
	}
	sort(a,a+p);
	for(int i=p-1;i>=0;i--){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
