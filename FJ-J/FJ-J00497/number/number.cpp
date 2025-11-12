#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010] = {-1},k = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l = s.size();
	for(int i = 0;i<l;i++){
		char c = s[i];
		if(c>='0'&&c<='9'){
			a[k++] = c-'0';
		}
	}
	sort(a,a+k,greater<long long>());
	for(int i = 0;i<k;i++){	
		cout<<a[i];
	}
	return 0;
}
