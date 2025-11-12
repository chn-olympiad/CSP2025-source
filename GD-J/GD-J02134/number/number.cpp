#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],box[1000000],maxx=0,ans,vis[1000000];
int n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9' ){
			a[n]=s[i]-48;
			n++;
		}
	}
	n--;
	if(n==1){
		cout<<a[1];
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}

	return 0;
} 
