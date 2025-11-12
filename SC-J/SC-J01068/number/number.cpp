#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
string s;
struct Number{
    long long a;
}number[N];
bool cmp(Number a,Number b){
	return a.a>b.a;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	cin>>s;
	long long len=s.length(),cnt=0;
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			number[++cnt].a=s[i]-'0';
		}
	} 
	sort(number+1,number+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<number[i].a;	
	}
	return 0;
} 