#include<bits/stdc++.h> 
using namespace std;
int main(){
	ifstream in("replace.in");
	ofstream out("replace.out");
	int n,q;
	in>>n>>q;
	vector<pair<string,string> > v(n);
	for(int i=0;i<n;i++){
		in>>v[i].first>>v[i].second;
	}
	for(int i=0;i<q;i++){
		int cnt=0;
		string t1,t2;
		in>>t1>>t2;
		for(int j=0;j<n;j++){
			int index=t1.find(v[j].first);
			if(index!=-1){
				string temp=t1.substr(0,index);
				temp=temp+v[j].second;
				temp=temp+t1.substr(index+v[j].first.size());
				if(temp==t2){
					//cout<<temp<<'\n';
					cnt++;
				}
			}
		}
		out<<cnt<<'\n';
	}
	return 0;
}
