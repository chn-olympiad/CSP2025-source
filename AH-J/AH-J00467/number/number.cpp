#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k;
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin>>s;
	k=0;
	int l=s.size();
	for (int i=0;i<l;i++){
		char c=s[i];
		if ('0'<=c && c<='9'){
			k++;
			a[k]=c-'0';
		}
	}
	sort (a+1,a+1+k);
	if (a[k]==0) {
		cout<<0;
		return 0;
	}
	for (int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
