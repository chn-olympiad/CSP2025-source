#include<bits/stdc++.h>
using namespace std;
long long x=0,sum=0;
long long a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long l=s.size();
	for(int i=0; i<=l; i++){
		if(s[i]=='0' || s[i]=='1'|| s[i]=='2'|| s[i]=='3' || s[i]=='4'|| s[i]=='5'|| s[i]=='6' || s[i]=='7'|| s[i]=='8'|| s[i]=='9'){
				x++;
				a[x]=int (s[i]) ;
		}
	}
	sort(a,a+x+1);
	for(long long  i=1000011; i>=1; i--){
		if(a[i]!=0){
			cout<<a[i]-48;
		}
	}
	
	return 0;
}
