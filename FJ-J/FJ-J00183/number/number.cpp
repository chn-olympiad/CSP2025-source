#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
long long d[N],p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){	
			p++;
			d[p]=s[i]-48;
		}
	}
	sort(d+1,d+p+1);
	for(int i=p;i>=1;i--){
		cout<<d[i];
	}
	return 0;
}

