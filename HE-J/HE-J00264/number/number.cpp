#include<bits/stdc++.h>
using namespace std;
int a[1000010]={0};
int ans=0;
bool dp[1000010]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans]=s[i]-'0';
			dp[ans]=true;
			ans++;
		}
	}
	sort(a,a+ans);
	for(int i=l-1;i>=0;i--){
		if(dp[i]) cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
