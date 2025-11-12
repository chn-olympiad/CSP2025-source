#include<bits/stdc++.h>
using namespace std;
int n,q;
unordered_map<string,string> mp;
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--){
		string ypy,zyb;
		cin>>ypy>>zyb;
		mp[ypy]=zyb;
	}
	while(q--){
		ans=0;
		string x,y;
		cin>>x>>y;
		int l1=x.size();
//		string a=x.substr(2,(3-2+1));
//		string ypy=x.substr(0,(2+1))+mp[a]+x.substr(3+1,l1-3+1); 
//		cout<<"11111 "<<ypy<<endl;
		for(int i=0;i<l1;i++){
//			cout<<"ypy"<<endl;
			for(int j=i;j<l1;j++){
				string a=x.substr(i,(j-i+1));
				string ypy=x.substr(0,(i))+mp[a]+x.substr(j+1,l1-j); 
//				cout<<ypy<<endl;
				if(ypy==y){
//					cout<<a<<endl;
					ans++;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
