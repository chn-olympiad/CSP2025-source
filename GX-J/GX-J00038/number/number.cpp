#include<bits/stdc++.h>
using namespace std;
string s;
char p;
long long l,a[1000000];
bool cmp(long long x,long long y){
return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=s[i]-'0';
			++l;
		}
	}
	sort(a,a+l,cmp);
	for(long long i=0;i<l;++i)
	cout<<a[i];
return 0;
}
