#include<bits/stdc++.h>
using namespace std;
long long a[1000005],i;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//------------------------------------------------------
	cin>>s;
	long long l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&a[i]<='9'){
			a[i]=s[i]-'0';
			}
	}
	sort(a,a+l);
	for(long long i=0;i<l;i++){
		cout<<a[i];
	}
	//------------------------------------------------------
	fclose(stdin);
	fclose(stdout);
	return 0;
}
