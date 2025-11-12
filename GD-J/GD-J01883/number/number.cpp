#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
} 
