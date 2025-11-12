#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=1;
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=2;i--){
		cout<<a[i];
	}
	return 0;
} 