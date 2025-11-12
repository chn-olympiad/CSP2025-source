#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}	
	sort(a+1,a+cnt+1);
	bool f=0;
	for(int i=1;i<=cnt;i++){
		if(a[i]!=0){
			f=1;
			break;
		}
	}
	if(f){
		for(int i=cnt;i>=1;i--){
			cout<<a[i];
		}
	}else{
		cout<<0<<endl;
	}
	
	return 0;
}
