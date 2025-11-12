#include<bits/stdc++.h>
using namespace std;
int jie=0;
void ti(string s1,string s2, string s3,string s4){
	for(int i=0;i<s1.size();i++){
		int y=1;
		for(int j=i;j<i+s3.size();j++){
			if(j>s3.size()){
				y=0;
				break;
			}
			if(s3[j-i]!=s1[j]){
				y=0;
				break;
			}
		}
		if(y){
			y=1;
			for(int j=i;j<i+s4.size();j++){
				if(j>s4.size()){
					y=0;
					break;
				}
				if(s4[j-i]!=s2[j]){
					y=0;
					break;
				}
			}
			jie+=y;
		}
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[n];
	string s2[n];
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		string s3,s4;
		cin>>s3>>s4;
		for(int j=0;j<n;j++){
			ti(s1[j],s2[j],s3,s4);
		}
		cout<<jie<<"\n";
		jie=0;
	}
	return 0;
}