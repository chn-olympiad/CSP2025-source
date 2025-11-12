#include<bits/stdc++.h>
using namespace std;
long long ans[1000010],len=1;
string s;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
			ans[len++]=(int)(s[i]-'0');
	}
	sort(ans+1,ans+len-1,cmp);
	for(int i=1;i<=len-1;i++)
		cout<<ans[i];
	
	fclose(stdin);
	fclose(stdout);
}
