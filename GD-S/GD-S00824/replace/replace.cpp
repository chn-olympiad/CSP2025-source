#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> pss;
int n,q,cnt=0;
pss strs[200003]={};
pss ques;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>strs[i].first>>strs[i].second;
	}
	for(int i=1;i<=q;i++){
		cin>>ques.first>>ques.second;
		string s=ques.first;
		for(int j=1;strs[j].first!="";j++){
			if(ques.first.find(strs[j].first)!=string::npos){
				int pos=ques.first.find(strs[j].first);
				ques.first.replace(pos,strs[j].second.size(),strs[j].second);
				if(ques.first==ques.second){
					cnt++;
				}
				ques.first=s;
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
}
