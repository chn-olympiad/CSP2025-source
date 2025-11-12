#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
string s;
int a[N],p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		char c=s[i]; 
		if('0'<=c&&c<='9')a[++p]=c-'0';
	}
	sort(a+1,a+p+1);
	for(int i=p;i>=1;i--)cout<<a[i];
	
	return 0;
} 
