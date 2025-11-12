#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+3;
string s;
int a[maxn],b[maxn],k;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			k++;
			b[i]=a[i];
		}
	}
	sort(b,b+k);
	for(int i=k;i>0;i--){
		if(b[i]<b[i-1]){
			swap(b[i-1],b[i]);
		}
		cout<<b[i];
	}
	return 0;
}
