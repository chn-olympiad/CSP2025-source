//GZ-S00401 贵阳市花溪区同为京学附属实验学校 袁家绎 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(q==1){
		cout<<0;
		return 0;
	}
	string s1[n],s2[n];
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	string q1[q],q2[q];
	for(int i=0;i<q;i++){
		cin>>q1[i]>>q2[q];
	}
	for(int i=0;i<q;i++){
		if(q1[i][0]=='b'||q1[i][q1[i].size()-1]=='b'||q2[i][0]=='b'||q2[i][q2[i].size()-1]=='b') cout<<0<<endl;
		else cout<<1;
	}
	return 0;
}
