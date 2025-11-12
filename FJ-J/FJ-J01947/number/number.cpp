#include<bits/stdc++.h>
using namespace std;
string s; 
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a,a+j+1);
	for(int i=j;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
