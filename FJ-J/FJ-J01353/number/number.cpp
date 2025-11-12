#include<bits/stdc++.h>
using namespace std;
int a,q,p;
string s;
map<int,int> ss;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ss[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(ss[i]>0){
			while(ss[i]--){
				cout<<i;
			}
		}
	} 
	
	
	
	
	return 0;
}
