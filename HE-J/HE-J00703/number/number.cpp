#include<bits/stdc++.h>
using namespace std;
int s1[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a=s.size();
	long long n=0;
	for(long long i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1[n]=s[i]-'0';
			n++;
		}
	}
	sort(s1,s1+n);
	for(int i=n-1;i>=0;i--){
		cout<<s1[i];
	}
	return 0;
}
