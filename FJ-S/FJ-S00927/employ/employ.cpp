#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(m==n){
		for(int i=0;i<n;i++)
			if(s[i]=='0'){
				cout<<0<<endl;
				return 0;
			}
		cout<<1<<endl;
		return 0;
	}
	bool flag=true;
	for(int i=0;i<n;i++)
		if(s[i]=='0'){
			flag=false;
			break;
		}
	if(flag){
		cout<<1<<endl;
		return 0;
	}
	
	return 0;
}
