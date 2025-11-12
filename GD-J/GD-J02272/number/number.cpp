#include<bits/stdc++.h> 
using namespace std;
string s,ans;
char num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') num[i]=s[i];
	}
	sort(num,num+len,greater<char>());
	for(int i=0;i<len;i++){
		ans+=num[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
