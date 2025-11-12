#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000010;
int a[N],b=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=int(s[i]-'0'); 
			b++;
		} 
	}
	sort(a,a+b);
	for(int i=b-1;i>=0;i--) cout<<a[i];
	return 0;
} 
