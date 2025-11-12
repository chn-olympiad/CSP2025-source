#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	long long a[11]={0};
	
	for(int i=0;i<s.size();i++)	{
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	
	string x="";
	
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			x+=(i+48);
		}
	}
	
	if(x[0]=='0'){
		cout<<0<<endl;
		return 0;
	}	
	
	cout<<x;	
		
	fclose(stdin);
	fclose(stdout);

	return 0;
	
}
