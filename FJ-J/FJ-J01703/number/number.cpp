#include<bits/stdc++.h>
using namespace std;
string s;
short int ans[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[j]=int(s[i]-'0');
			j++;
		}
	}
	sort(ans+1,ans+1+j,cmp);
	for(int i=1;i<j;i++)cout<<ans[i];
	return 0;
}
