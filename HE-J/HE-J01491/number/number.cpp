#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt=1;
int a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt+1);
	for(long long i=cnt;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
