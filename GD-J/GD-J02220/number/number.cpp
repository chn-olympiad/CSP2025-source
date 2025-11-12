#include<bits/stdc++.h>
using namespace std;
string s;long long a[2000005],idx; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0')a[idx++]=s[i]-'0';
	}
	sort(a,a+idx);
	for(int i=idx-1;i>=0;i--)cout<<a[i];
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	return 0;
}//
