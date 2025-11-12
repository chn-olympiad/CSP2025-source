#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int len=s.size();
	int j=0;
	
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') {
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--) cout<<a[i];
}