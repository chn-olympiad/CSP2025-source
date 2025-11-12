#include<bits/stdc++.h>
using namespace std;
int n,l[1000005]={},j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	cin>>s1;
	n=s1.size();
	for(int i=0;i<n;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			l[j]=s1[i]-'0';
			j++;
		}
	}
	sort(l,l+j);
	for(int i=j-1;i>=0;i--){
		cout<<l[i];
	}
	return 0;
}
