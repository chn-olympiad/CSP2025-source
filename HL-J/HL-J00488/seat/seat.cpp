#include<iostream>
using namespace std;
long long n,m;
string s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a=s[1];
	for(int i=0;i<s.size();i++){
		if(s[i]<s[i+1]){
			s[i]=s[i+1];
			s[i+1]=s[i];
		}
	}
	int b=(s[1]-a)+1;
	m=(b+1)/n;
	n=m-(b%2-1);
	cout<<m<<" "<<n;
	return 0;
}