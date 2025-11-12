#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string x,y;
};
node a[200100];
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		mp[a[i].x]=a[i].y;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		long long c=0;
		if(s1.size()!=s2.size()){
			cout<<0<<'\n';
			continue;
		}
		
		for(auto er:mp){
			int p=s1.find(er.first);
			while(p!=-1){
//				cout<<p<<" "<<p+er.second.size()<<" "<<s1.size()-(p+er.second.size())<<'\n';
				string x=s1.substr(0,p),y=er.second,z=s1.substr(p+er.second.size(),s1.size()-(p+er.second.size()));
				
				if(x+y+z==s2){
					c++;
					break;
				}
				bool f=0;
				for(int j=0;j<er.first.size();j++){
					if(s1[j+p]!=s2[j+p]){
						f=1;
						break;
					}
				}
				if(f){
					break;
				}else{
					s1.erase(p,er.first.size());
					s2.erase(p,er.first.size());
					p=s1.find(er.first);
				}
			}
			
		}
//		for(int i=1;i<=s1.size();i++){
//			x="";
//			y=s1.substr(0,i);
//			z=s1.substr(i,s1.size()-i);
//			if(i==s1.size()){
//				z="";
//			}
//			for(int j=0;j<=s1.size()-i;j++){
//				if(x+mp[y]+z==s2){
//					c++;
//					cout<<x<<" "<<y<<" "<<z<<'\n';
//				}
//				x=x+s1[j];
//				y.erase(0,1);
//				y=y+s1[j+i];
//				z.erase(0,1);
//			}
//		}
		cout<<c<<'\n';
	}
	return 0;
}

