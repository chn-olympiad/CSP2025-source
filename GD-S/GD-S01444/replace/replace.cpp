#include<bits/stdc++.h>
using namespace std;
vector<string> t1(2e5);
vector<string> t2(2e5);

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
	}
	
	while(q--){
		string s1,s2,n1;
		cin>>s1>>s2;
		int c=0,si1=s1.size(),si2=s2.size();
		for(int i=1;i<=n;i++){
			int a=s1.find(t1[i]);
			if(s1.find(t1[i])&&s2.find(t2[i])&&t1[i].size()==t2[i].size()&&s1.find(t1[i])==s2.find(t2[i])){
				if(s1.substr(0,a)!=t1[i]&&s2.substr(0,a)!=t2[i]){
					n1=s1.substr(0,a)+t2[i]+ s1.substr(s1.find(t1[i])+t1[i].size() , si1-s1.find(t1[i])-t1[i].size());
				}
				if(n1==s2){
					c++;
				}
			}
		}
		cout<<c<<endl;
	}
	
	return 0;
} 
