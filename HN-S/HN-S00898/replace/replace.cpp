#include<bits/stdc++.h>
using namespace std;

int n,q,ans=0;
map<string,string> s;
vector<string> xrr(200010),zrr(200010);

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++) {
		string temp1,temp2;
		cin>>temp1>>temp2;
		s[temp1]=temp2;
		s[temp2]=temp1;
	}
	while(q--){
		ans=0;
		bool isX=false,isZ=false;
		string x="",z="";
		string t1,t2;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++){
			if(t1[i]==t2[i]) {
				isX=true;
				x.push_back(t1[i]);
				xrr.push_back(string(x)); 
			}
			else break;
		}
		for(int i=t1.size()-1;i>-1;i--){
			if(t1[i]==t2[i]) {
				isZ=true;
				z.push_back(t1[i]);
				zrr.push_back(string(z));
			}
			else break;
		}
		string newS=t1;
		if(isX&&isZ){
			for(int i=0;i<xrr.size()&&i<=newS.size();i++){
				for(int j=0;j<zrr.size()&&j<=newS.size();j++){
					newS=t1;
					newS.erase(0,i);
					newS.erase(newS.size()-1-j,j);
					try{
						newS=s[newS];
					}catch(exception){
						continue;
					}
					string x1=xrr[i];
					swap(x1,newS);
					for(int k=0;k<x1.size();k++) newS.push_back(x1[k]);
					for(int k=0;k<zrr[j].size();k++) newS.push_back(zrr[j][k]);
					if(newS==t2) ans++;					
				}
			}
		}
		else if(isX){
			for(int i=0;i<xrr.size()&&i<=newS.size();i++){
				newS=t1;
				newS.erase(0,i);
				try{
					newS=s[newS];
				}catch(exception){
					continue;
				}
				string x1=xrr[i];
				swap(x1,newS);
				for(int k=0;k<x1.size();k++) newS.push_back(x1[k]);
				if(newS==t2) ans++;	
			}
		}else if(isZ){
			for(int i=0;i<xrr.size()&&i<=newS.size();i++){
				newS=t1;
				newS.erase(newS.size()-1-i,i);
				try{
					newS=s[newS];
				}catch(exception){
					continue;
				}
				for(int k=0;k<zrr[i].size();k++) newS.push_back(zrr[i][k]);
				if(newS==t2) ans++;	
			}
		}
		newS=t1;
		try{
			newS=s[newS];
		}catch(exception){
			cout<<ans<<endl;
			continue;
		}
		if(newS==t2) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
