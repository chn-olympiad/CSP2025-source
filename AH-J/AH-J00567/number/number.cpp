#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a[10000005],t=0,js=0;
long long sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	getline(cin,s);
	t=s.size();
	for(int i=0;i<t;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[js]=s[i]-'0';
			js++;
		}
	}

	sort(a,a+js+1);

	for(int i=js;i>0;i--){
		
		s1+=a[i]+'0';
	}
	cout<<s1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
