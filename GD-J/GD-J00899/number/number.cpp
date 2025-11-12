#include<bits/stdc++.h>
using namespace std;
bool vis[1000000+100];
string ans;
bool flag;
char sum='0',cnt;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		sum='0';
		for(int j=0; j<s.size(); j++) {
			if(sum<=s[j]&&(!vis[j])&&s[j]>='0'&&s[j]<='9'){
				sum=s[j];
				cnt=j;
				flag=1;
			}
		}
		if(flag){
			ans+=sum;
			vis[cnt]=1;
		}
		flag=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
