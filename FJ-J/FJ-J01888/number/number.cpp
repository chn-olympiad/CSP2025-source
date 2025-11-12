#include<bits/stdc++.h>
using namespace std;

int sum=0,ans[1000005];
string s;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9'){
			sum++;
			ans[sum]=s[i]-'0';
		}
	sort(ans+1,ans+sum+1,cmp);
	for(int i=1;i<=sum;i++)
		cout<<ans[i];
	return 0;
}
