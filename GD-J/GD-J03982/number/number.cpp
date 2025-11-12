#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int s[1000001],sum=0,sum2=0;
	cin>>n;
	int t=n.size();
	for(int i=0;i<t;i++){
		if(n[i]>='0'&&n[i]<='9'){
			s[sum]=n[i]-48;
			sum++;
			if(n[i]=='0')sum2++;
		}
	}
	sort(s,s+t,check);
	for(int i=t;i>=0;i--){
		if(s[i]!=0){
			cout<<s[i];
		}
	}
	for(int i=1;i<=sum2;i++)cout<<0;
	return 0;
}

