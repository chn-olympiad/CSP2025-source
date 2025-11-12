#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,x,y,a[N],c;
string s,s1,s2;
struct No{
	long long h,r;
};
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			c++;
			a[c]=s[i]-'0';
		}
	}
	sort(a+1,a+c+1,cmp);
	for(int i=1;i<=c;i++)cout<<a[i];
	return 0;
}
