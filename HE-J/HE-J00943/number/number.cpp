#include <bits/stdc++.h>
using namespace std;

long long a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int x=1;
	cin>>s;
	int lenth=s.size();
	for(int i=0;i<lenth;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-48;
			++x;
		}
	}
	sort(a+1,a+x);
	for(int i=x-1;i>=1;i--){
		cout<<a[i];
	}
		
	return 0;
}
