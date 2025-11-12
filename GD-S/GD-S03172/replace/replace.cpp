#include<bits/stdc++.h>
using namespace std;
const int N=200020;
int n,q,x,y,ans;
int flag;
string s[N][2];
string s1,s2;
int main(){

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='b') x=s1[i];
		if(s1[i]!='a') flag++;
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='b') y=s2[i];
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
		int a,b;
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]=='b') a=i;
		} 
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]=='b') b=i;
		} 
		if(a-b==x-y && x>=a && s1.size()-x>=s[i][0].size()-a && y>=b && s2.size()-y>=s[i][1].size()-b){
			ans++;
		}
		}
		cout<<ans<<endl;
	}else cout<<0;
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
