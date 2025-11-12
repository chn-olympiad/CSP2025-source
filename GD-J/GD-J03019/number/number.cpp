#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
char ar[N];
long long n,k,m,h,l,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n = s.size()-1;
	for(int i = 0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ar[k++] = s[i];
		}
	}
	sort(ar,ar+k,greater<int>());
	for(int i = 0;i<=k;i++){
		cout<<ar[i];
	}
	return 0;
} 
