#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int as=1,d=s.size();
	for(int i=0;i<d;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[as]=s[i]-'0';
			as++;
		}
	}
	sort(a+1,a+1+as);
	for(int i=as;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
