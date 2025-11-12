#include<bits/stdc++.h>
using namespace std;
long long a[1000001],ans,j=1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[j++]=s[i]-'0';
	for(int k=9;k>=0;k--){
		for(int i=1;i<j;i++){
			if(a[i]==k){
				cout<<a[i];
				a[i]=-1;
			}
		}
	}
	return 0;
}
