#include<bits/stdc++.h>
using namespace std;
string s;
int k=0;
int l[1000020];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
			l[k]=s[i]-'0';
			k++;
		}
		if(s[i]=='0'){
			l[k]=-1;
			k++;
		}
	}
	sort(l,l+k);
	for(int i=k-1;i>=0;i--){
		if(l[i]==0){
			continue;
		}
		if(l[i]==-1){
			cout<<0;
			continue;
		} 
		cout<<l[i];
	}
	return 0;
} 
