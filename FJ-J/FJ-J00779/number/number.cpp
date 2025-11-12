#include<bits/stdc++.h>
#include<cstring>
using namespace std;
string s;
int a[1000010],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;

	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]= s[i] - 48;
			n++;     
		}
	}
	sort(a,a+n);
	for(int i = n-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
