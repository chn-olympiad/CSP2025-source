#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s,a="",b="";
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]>=49&&s[i]<=57){
			a+=s[i];
		}
	}
	string c="0",ans="";
	int d,e=a.size();
	while(e>0){
		for(int i=1;i<=a.size();i++){
			if(a[i]>=49&&a[i]<=57&&c[1]<=a[i]){
				c[1]=a[i];
				d=i;
			} 
		}
		a[d]='s';
		ans+=c[1];
		c="0";
		e--;
	}
	
	cout<<ans;
	return 0;
}
