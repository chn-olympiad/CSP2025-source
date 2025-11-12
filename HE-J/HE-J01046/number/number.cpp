#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	cout<<n<<endl;
	int a[n];
	for(int i=0;i<n;i++){
		if(int(s[i]-48)<=9 && int(s[i]-48)>=0){
			a[i]=int(s[i]-48);
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
