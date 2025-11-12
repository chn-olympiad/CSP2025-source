#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
long long n=0;
int cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
} 
