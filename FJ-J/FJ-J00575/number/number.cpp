#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010];                                  
int main(){
	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	long long x=0;
	for(long long i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=int(s[i])-48;
		}
	}
	sort(a+1,a+x+1);
	for(long long i=x;i>=1;i--){
		cout<<a[i];
	}
	return 0; 
}
