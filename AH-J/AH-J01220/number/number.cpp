#include <bits/stdc++.h>
using namespace std;
string s;
long long a[15],b,c,x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	x=s.size();
	for(int i=0;i<=x;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	for(int i=0;i<10;i++){
		if(a[i]!=0){
			c+=a[i];
		}
	}
	for(int i=9;i>=0;i++){
		while(a[i]!=0){
			b+=i*pow(10,c);
			if(i==0){
				b*=10;
			}
		}
	}
	cout<<b;
	return 0;
}
