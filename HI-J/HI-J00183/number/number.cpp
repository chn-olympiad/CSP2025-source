#include<bits/stdc++.h>
using namespace std;
string s;
long long n, t;
int a[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			t=(int)s[i]-'0';
			a[n] = t;
			n++;
		}
	}
	sort(a,a+n,cmp);
	for(long long i=0;i<n;i++){
		printf("%d",a[i]);
	}
	return 0;
}
