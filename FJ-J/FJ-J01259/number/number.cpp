#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
int k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-48;
		}
	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
