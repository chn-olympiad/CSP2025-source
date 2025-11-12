#include <bits/stdc++.h>
using namespace std;
string s;
long long i,n,a[1000001],j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	j--;
	for(i=j;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
