#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int l,a[10000005],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=(int)s[i]-48;
			j++;
		}
	}sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}//AFO