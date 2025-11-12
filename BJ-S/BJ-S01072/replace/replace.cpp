#include<bits/stdc++.h>
using namespace std;

int n,q,res;
unordered_multimap<string,string> cg;

int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
	cin>>n>>q;
	pair<string,string> t;
	for(int i=1;i<=n;i++){
		cin>>t.first>>t.second;
		cg.insert(t);
	}
	string t1,t2;
	while(q--){
		res=0;
		cin>>t1>>t2;
		int l=-1,r=-1;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		string sub1=t1.substr(0,r),sub2=t2.substr(0,r);
		for(int i=0;i<=l;i++){
			for(int j=r;j<=n;j++){
				sub1+=t1[j];
				sub2+=t2[j];
// cerr<<i<<"~"<<j<<" "<<(cg.find(sub1)!=cg.end()&&cg.find(sub1)->second==sub2)<<"\n";
// cerr<<" "<<sub1<<"\n";
// cerr<<" "<<sub2<<"\n";
				if(cg.find(sub1)!=cg.end()&&cg.find(sub1)->second==sub2)
					res++;
			}
			sub1.erase((sub1.size()-1)-(n-r+1)+1,n-r+1);
			sub2.erase((sub2.size()-1)-(n-r+1)+1,n-r+1);
			sub1.erase(0,1);
			sub2.erase(0,1);
		}
		cout<<res<<"\n";
	}
	return 0;
}