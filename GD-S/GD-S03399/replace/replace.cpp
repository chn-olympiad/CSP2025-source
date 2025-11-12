#include<bits/stdc++.h>
using namespace std;
string gz[100000][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>gz[i][1]>>gz[i][2];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			string l1=t1,l2=t2;
			int w=l1.find(gz[i][1]);
			while(w!=-1){
				bool fl1=l1.substr(0,w)==l2.substr(0,w),fl2=l2.substr(w,gz[i][1].size())==gz[i][2],fl3=l1.substr(w+gz[i][1].size())==l2.substr(w+gz[i][1].size());
				if(fl1 && fl2 && fl3){
					ans++;
					break;
				}
				else if(fl1==0){
					break;
				}
				else if(fl2==1){
					break;
				}
				else if(l2.substr(w,gz[i][1].size())!=l1.substr(w,gz[i][1].size())){
					break;
				}
				l1.substr(w+gz[i][1].size());
				l2.substr(w+gz[i][1].size());
				w=l1.find(gz[i][1]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
