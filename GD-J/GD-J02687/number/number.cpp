#include<bits/stdc++.h>
using namespace std;
const int MX=1e6+5;
int a[MX];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	string s;cin>>s;
	int l=s.size(),sum=0;
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		if(sum){
			cout<<a[i];
			sum--;
		}
	}
	return 0;
}
