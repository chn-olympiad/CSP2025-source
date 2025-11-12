#include<bits/stdc++.h>
using namespace std;
int n,r,ans=0;
vector<vector<string> > th;
vector<vector<string> > jc;
string thstr(string str,string t1,string t2){
	if (t1==str) return t2;
	if (str.size()==1 && t1.size()==1 && t2.size()==1){
		if (t1!=str) return str;
	}
	if (str.size()<t1.size()) return str;
	int findnum=0,qd=-1;
	bool findflag=false;
	for (int i=0;i<str.size();i++){	
		if (findnum==t1.size()){
			findflag=true;
			break;
		}
		if (str[i]==t1[findnum]){
			if (findnum==0) qd=i;
			findnum++;
		}else{
			findnum=0;
		}
	}
	if (findflag){
		for (int i=qd;i<qd+findnum;i++){
			str[i]=t2[i-qd];
		}
		return str;
	}else{
		return str;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>r;
	th = vector<vector<string> > (n,vector<string> (2,""));
	jc = vector<vector<string> > (r,vector<string> (2,""));
	for (int i=0;i<n;i++){
		cin>>th[i][0]>>th[i][1];
	}
	for (int i=0;i<r;i++){
		cin>>jc[i][0]>>jc[i][1];
		if (jc[i][0]==jc[i][1] || jc[i][0].size()!=jc[i][1].size()){
			cout<<0<<endl;
		}else{
			for (int j=0;j<n;j++){
				if (thstr(jc[i][0],th[j][0],th[j][1])==jc[i][1]){
					ans++;
				}
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
    return 0;
}


