#include<bits/stdc++.h>
using namespace std;
string a;
int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len=s.size();
	int j=0;
	int ans=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i];
			j++;
			ans++;
		}
	}
	long long b[100005];
	for(int i=0;i<ans;i++){
		b[i]=(int)(a[i]);	
	}
	sort(b,b+ans);
	for(int i=ans-1;i>=0;i--){
		cout<<(char)(b[i]);
	}
	return 0;
}