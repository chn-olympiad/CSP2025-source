#include<bits/stdc++.h>
using namespace std;
long long a[7500010],cnt=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			cnt++;
			a[cnt]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+cnt);
	for(long long i=cnt;i>=1;i--){
		cout<<a[i];
	} 
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
