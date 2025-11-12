#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
string kb[int(2e5)+7];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
		kb[i]=a;
	}
	for(int m=0;m<q;m++){
		string ta,tb;
		cin>>ta>>tb;
		int s=0;
		for(int i=0;i<ta.size();i++)
			for(int j=0;j<n;j++)
				if(ta.substr(i,kb[i].size())==kb[i]){
					if(ta.substr(0,i)+mp[kb[i]]+ta.substr(i+kb[i].size()-1,ta.size()-i-kb[i].size())==tb)
						s++;
				}	
		cout<<s<<endl;
	}
	return 0;
}
/*
1 1
xabcx xadex
xabcx xadex
*/
