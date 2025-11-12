#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size(),j=0;
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	j--;
	sort(a,a+j,cmp);
	for(long long i=0;i<=j;i++){
		cout<<a[i];
	}
	return 0;
}
