#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x = 1;
	for(int i = 0; i <= int(s.size()) - 1; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[x] = s[i] - '0';
			x++;
		} 
	}
	sort(a+1,a+x);
	for(int i = x - 1; i >= 1; i--){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
} 
