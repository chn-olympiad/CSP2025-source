#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std; 
#define int long long 

int n,q; 
string str[210000][5];
string s,ss;
int sz;
void do_it(){
	cin>>s>>ss;
	sz=s.size();
	int accm=0;
	for(int i=0;i<sz;i++){
		for(int j=1;j<=n;j++){
			if(i+str[j][1].size()-1<sz){
				if(s.substr(i,str[j][1].size())==str[j][1] && ss.substr(i,str[j][2].size())==str[j][2]
				 && s.substr(0,i)==ss.substr(0,i) && s.substr(i+str[j][1].size())==ss.substr(i+str[j][1].size())){
					//cout<<"substr:"<<i<<' '<<j<<endl;
					//cout<<"find:"<<s.substr(i,str[j][1].size())<<endl;
					accm++;
				}
			}
		}
	}
	cout<<accm<<endl;
}

vector<pair<string,string> > temp;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string ss1,ss2;
		cin>>ss1>>ss2;
		temp.push_back(make_pair(ss1,ss2));
	}
	sort(temp.begin(),temp.end());
	unique(temp.begin(),temp.end());
	int newn=1;
	for(int i=2;i<=temp.size();i++){
		if(temp[i-1]>temp[i-2]){
			newn++;
		}
		if(temp[i-1]<=temp[i-2]){
			break;
		}
	}
	n=newn;
	for(int i=0;i<n;i++){
		str[i+1][1]=temp[i].first;
		str[i+1][2]=temp[i].second;
	}
	temp.clear();
	while(q--){
		do_it();
	}
	return 0;
}
