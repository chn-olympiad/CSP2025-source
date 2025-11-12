#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,a[N+5],asuoyin=1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[asuoyin]=s[i]-'0';
			asuoyin++;
			
		}
	}
	asuoyin--;
	sort(a+1,a+asuoyin+1);
	for(int i=asuoyin;i>=1;i--){
		cout<<a[i];
	}
	return 0;
	
	
}
 
