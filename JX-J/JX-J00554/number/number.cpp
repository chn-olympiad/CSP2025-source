#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
int k,w;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	w=s.size();
	for(int i=0;i<w;i++){
		if(s[i]>=48&&s[i]<=57){
			k++;
			a[k]=s[i]-48;
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
