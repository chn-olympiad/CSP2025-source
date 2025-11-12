#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
return x>y;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
long long n=s.size();
long long a[n],num=0;
for(long long i=0;i<n;i++){
	if(s[i]>='0'&&s[i]<='9'){
		a[num]=s[i]-'0';
		num++;
	}
}
sort(a,a+num,cmp);
for(long long i=0;i<num;i++){
cout<<a[i];
}
return 0;
}
