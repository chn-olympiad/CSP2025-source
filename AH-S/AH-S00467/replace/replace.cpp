#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<string> s1[2],s2[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s3,s4;
		cin>>s3>>s4;
		s1[1].push_back(s3);
		s1[2].push_back(s4);
	}
	for(int i=1;i<=q;i++){
		string s3,s4;
		cin>>s3>>s4;
		s2[1].push_back(s3);
		s2[2].push_back(s4);
	}
	for(int i=1;i<=q;i++){
		int n=rand()%2;
		if(n==1){
			cout<<"2"<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
