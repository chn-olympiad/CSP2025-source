#include<bits/stdc++.h>
using namespace std;
string to_two(int x){
	if(x==0)return "0";
	if(x==1)return "1";
	string ans;
	while(x>0){
		ans+=char('0'+x%2);
		x/=2;
	}
	for(int i=0;i<=ans.length()-i-1;i++){
		char c=ans[i];
		ans[i]=ans[ans.length()-i-1];
		ans[ans.length()-i-1]=c;
	}
	return ans;
}
string yh(string s1,string s2){
	string ans;
	int x=0;
	if(s1.length()<s2.length()){
		string s3=s1;
		s1=s2;
		s2=s3;
	}
	while(x<s1.length()-s2.length()){
		if(s1[x]=='1')ans+='1';
		else ans+='0';
		x++;
	}
	for(int i=0;i<s2.length();i++){
		if(s1[i+x]!=s2[i])ans+='1';
		else ans+='0';
	}
	return ans;
}
bool dy(string s1,string s2){
	int p=0,q=0;
	while(s1[p]=='0')p++;
	while(s2[q]=='0')q++;
	if(s1.length()-p!=s2.length()-q)return false;
	while(s1[p]==s2[q]){
		p++;
		q++;
		if(p>=s1.length()||q>=s2.length())return true;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=0;
	cin>>n;
	vector<string>a;
	string s[n+1][n+1],k;
	int dp[n+1][n+1]={0};
	{
		int kk=0;
		cin>>kk;
		k=to_two(kk);
	}
	for(int i=0;i<n;i++){
		int x=0;
		cin>>x;
		a.push_back(to_two(x));
		s[i][0]=a[i];
		dp[i][0]=dy(k,s[i][0]);
	}
	for(int i=0;i<n;i++){
		for(int j=1;i+j<n;j++){
			s[i][j]=yh(s[i][j-1],a[i+j]);
			dp[i][j]=dy(k,s[i][j]);
		}
	}
	int maxn[n+1]={0};
	maxn[n-1]=dp[n-1][0];
	for(int i=n-2;i>=0;i--){
		for(int j=i;j<n;j++){
			dp[i][j-i]+=maxn[j+1];
			maxn[i]=max(dp[i][j-i],maxn[i]);
		}
	}
	cout<<maxn[0];
	return 0;
} //4 3 2 1 0 3
