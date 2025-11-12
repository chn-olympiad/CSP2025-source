#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ans=s.size();
	if(ans==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<1000005;i++){
		b[i]=-1;
	}
	for(int i=ans;i>=1;i++){
		if(s[i]==0 || s[i]==1 || s[i]==2 || s[i]==3 || s[i]==4 || s[i]==5 || s[i]==6 || s[i]==7 || s[i]==8 || s[i]==9){
			b[i]=s[i];
		}
	}
	sort(b+1,b+ans+1);
	for(int i=ans;i>=1;i++){
		if(b[i]==-1)break;
		cout<<b[i];
	}
	return 0;
}
