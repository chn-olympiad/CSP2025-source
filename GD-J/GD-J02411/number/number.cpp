#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()];
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	for(int i=0;i<j-1;i++){
		for(int k=i+1;k<j;k++){
			if(a[i]<a[k]){
				int c;
				c=a[i];
				a[i]=a[k];
				a[k]=c;
			}
		}
	}
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
