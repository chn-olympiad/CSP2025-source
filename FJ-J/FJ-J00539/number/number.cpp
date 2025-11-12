#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000000];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	long long l=s.size()-1,j=0;
	for(int i=0;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=int(s[i]-48);
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
