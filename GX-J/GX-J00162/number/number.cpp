#include<bits/stdc++.h>
using namespace std;
string a;
long long b[10001],l=0;	
bool dd(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long s;
	for(int i=0;i<a.size();i++){
		s=a[i]-48;
		if(s>=0&&s<=9){
			b[l++]=s;
		}
	}
	sort(b,b+l,dd);
	for(int i=0;i<l;i++){
		cout<<b[i];
	}
	return 0;
}
