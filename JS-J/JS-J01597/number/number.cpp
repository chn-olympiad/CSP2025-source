#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000100],k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+1,a+k);
	for(int i=k-1;i>=1;i--){
		if(a[k-1]==0){
			cout<<0;
			return 0;
		}
		cout<<a[i];
	}
	return 0;
}
