#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000000],k=1; 
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+1,a+k,cmp);
	for(long long i=1;i<k;i++){
		cout<<a[i];
	}
	return 0;
}