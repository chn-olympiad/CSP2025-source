#include <bits/stdc++.h>

using namespace std;

//int getcount(vector<int>* ans,string t1,string t2,vector< vector<string> > rpl){
//	for(int i = 0;i < rpl.size();i++){
//		if(find(t1.begin(),t1.end(),rpl[i]) != t1.end()){
//			
//		}
//		
//	}
//}

int main(){
	vector<int> ans;
	freopen("replace.out","w",stdout);
	freopen("replace.in","r",stdin);
	vector<string> st1,q1;
	vector< vector<string> > st2,q2;
	string s1,s2,t1,t2;
	int n,q;//二元数组数量 问题数量
	for(int i = 0; i < n;i++){
		cin >> s1 >> s2;
		st1.push_back(s1);
		st1.push_back(s2);
		st2.push_back(st1);
		st1.clear();
	} 
	for(int i = 0; i < q;i++){
		cin >> t1 >> t2;
		q1.push_back(t1);
		q1.push_back(t2);
		q2.push_back(q1);
		q1.clear();
	}
//	for(int i= 0;i < q2.size();i++){
//		getcount(&ans,q2[i][0],q2[i][1],st2);
//	}
 	
	
	return 0;
} 
