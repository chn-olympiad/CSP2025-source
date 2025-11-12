#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			ans[cnt]=s[i]-48;
			//cout<<i<<" ";
			//cout<<ans[i]<<" ";
			cnt++;
			//cout<<cnt;
			
		}
	}
	sort(ans,ans+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<ans[i];
	}	
	
	return 0;
}
