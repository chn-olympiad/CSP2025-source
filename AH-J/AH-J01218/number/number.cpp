#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010];
int t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=1*s[i]-'0';
			t++;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
