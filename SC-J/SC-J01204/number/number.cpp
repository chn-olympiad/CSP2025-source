#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),m=0;
	for(int i=0;i<n;i++){
		if((int)s[i]<=57&&(int)s[i]>=48) a[++m]=s[i];
	}
	for(int i=1;i<=m;i++){
		b[a[i]]++;
	}
	for(int i=57;i>=48;i--){
		int j=b[i];
		for(int e=1;e<=j;e++){
			cout<<i-48;
		}
	}
	return 0;
}//99998888887777766666655555544444433332111000000000
 //9999888888777776666665555554444443333211100000000