#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000000],k,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[k]=s[i]-'0';
			k++;
		}
	}
	if(k==s.size()) {
		for(int i=0;i<k;i++){
			cout<<num[i];
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(num,num+k);
	int x=1;
	for(int i=0;i<k;i++){
		ans+=num[i]*x;
		x*=10;
	}
	fclose(stdin);
	fclose(stdout);
	cout<<ans;
	return 0;
}

