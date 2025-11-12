#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	long long n=s.size();
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,1+a+j);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
