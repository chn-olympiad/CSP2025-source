#include<bits/stdc++.h> 
using namespace std;
string s;
long long sum;
long long a[100005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+s.size()+1);
	if(s.size()==sum){
		for(int i=sum;i>=1;i--){
			cout<<a[i];
		}
	}
	else{
		for(int i=s.size();i>=sum;i--){
			cout<<a[i];
		}
	}
	
	return 0;
}
