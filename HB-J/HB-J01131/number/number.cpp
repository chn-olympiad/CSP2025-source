#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	memset(a,-1,sizeof(a));
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-48;
		}
	}
	sort(a,a+l,greater<int>());
	for(int i=0;i<l;i++){
		if(a[i]>-1) cout<<a[i];
	}
	
	return 0;
}
