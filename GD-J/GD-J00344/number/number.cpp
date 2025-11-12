#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	string s;
	cin>>s;
	int a[11],n=s.size();
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		if(48<=s[i]&&57>=s[i])
			a[int(s[i])-48]++;
	}
	bool b=true;
	for(int i=9;i>0;i--)
		if(a[i]!=0) b=false;
	if(!b){
		for(int i=9;i>=0;i--){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	else cout<<0;
	freopen("number.out","w",stdout);
	return 0;
} 
