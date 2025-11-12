#include<bits/stdc++.h>
using namespace std;
map <string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	string a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		for(int j=0;j<a.length();j++){
			for(int t=j;t<=a.length();t++){
				string dqx1="";
				string dqx2="";
				string dqx3="";
				string dqy1="";
				string dqy2="";
				string dqy3="";
				for(int i1=0;i1<j;i1++){
					dqx1+=a[i1];
					dqy1+=b[i1];
				}
				for(int i1=j;i1<=t;i1++){
					dqx2+=a[i1];
					dqy2+=b[i1]; 
				}
				for(int i1=t+1;i1<a.length();i1++){
					dqx3+=a[i1];
					dqy3+=b[i1];
				}
				if(dqx1==dqy1&&dqx3==dqy3&&mp[dqx2]==dqy2){
					cnt++;
				}
			}
		}
	    cout<<cnt<<endl;
	    cnt=0;
	}
	return 0;
}
