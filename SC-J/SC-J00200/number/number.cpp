#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(0);  
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("numbei.out","w",stdout);
	char c[1000005]={};
	int a[1000005]={};
	cin>>s;
	for(int i=0;i<=s.size();i++){
		c[i]+=s[i];
		//cout<<c[i]<<" ";
	}
	sort(c+1,c+s.size()+1);
	for(int i=s.size();i<=0;i++){
		if(c[i]<='9'&&c[i]>='0'){
			a[i]+=int(c[i]);
		}
		//cout<<a[i]<<" "; 
	}
	return 0;
} 