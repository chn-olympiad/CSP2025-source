#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000010];
ll k=0;
int main(){
	//ÒÑ±£´æ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-48;
		}
	}
	sort(&a[1],&a[k+1]);
	if(a[k]==0){
		cout<<"0";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(ll i=k;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
