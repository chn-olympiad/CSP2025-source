#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),x=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			string noww="";
			noww+=s[i];
			a[x]=stoi(noww);
			x++;
		}
	}
	x--;
	sort(a+1,a+x+1,greater<int>());
	string ans="";
	for(int i=1;i<=x;i++)
		ans+=to_string(a[i]);
		bool check=false;
	for(int i=0;i<x;i++){
		if(ans[i]!='0'){
			check=true;
			break;
		}
	} 
	if(check==true)
	    cout<<ans;
	else
	    cout<<0;
} 