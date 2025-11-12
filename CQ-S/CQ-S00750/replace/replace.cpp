#include <bits/stdc++.h>
using namespace std;
const int PD=1e9;
int n,q;
string s[200005],s1[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=q;i++){
		string qs,qs1;
		cin>>qs>>qs1;
		if(qs.size()!=qs1.size()){
			cout<<0;
		}
		else{
			string prb;
			int st=1e9,en=0,num=0;
			bool p=false;
			for(int j=0;j<qs.size();j++){
				if(qs[j]!=qs1[j]){
					p=true;
					en=j;
					st=min(st,j);
				}
			}
			for(int j=st;j<=en;j++){
				prb.append(1,qs[j]);
			}
			for(int j=1;j<=n;j++){
				if(s[j].find(prb)<PD&&qs1.find(s1[j])<PD&&qs1.find(s1[j])==st-s[j].find(prb)&&s[j].find(prb)<=st){
					num++;
				}
			}
			cout<<num;
		}
		if(i<q){
			cout<<endl;
		}
	}
	return 0;
}//40
