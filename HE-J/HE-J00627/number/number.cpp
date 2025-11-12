#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
long long ans=0,n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	if(n==1){
		cout<<a[0];
		return 0;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		ans+=a[i]*pow(10,i);
	}
	cout<<ans;
	return 0;
} 
