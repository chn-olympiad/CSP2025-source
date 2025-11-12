#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char c[1000005];
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			c[j]=s[i];
			j++;
		}
	}
	for(int i=0;i<=j-1;i++){
		for(int k=0;k<=j-1;k++)
			if(c[k]<c[k+1]){
				int t;
				t=c[k];
				c[k]=c[k+1];
				c[k+1]=t;
			}
	} 
	for(int i=0;i<=j-1;i++){
		cout<<c[i];
	}
	return 0;
}