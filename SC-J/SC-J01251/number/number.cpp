#include<bits/stdc++.h>
using namespace std;
int p[1000010],sum=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			p[sum]=s[i]-'0';
			sum++;
		}
	}
	sort(p+1,p+sum);
	for(int i=sum-1;i>=1;i--){
		cout<<p[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 