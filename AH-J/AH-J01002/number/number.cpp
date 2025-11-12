#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	string s;
	cin>>s;
	long long n=s.size()-1;
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k=k+1;
			a[k]=int(s[i]-'0');
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--) printf("%d",a[i]);
	return 0;
}
