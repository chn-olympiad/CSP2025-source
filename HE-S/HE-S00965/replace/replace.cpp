#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		string t1,t2,t3;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2){
			cout<<"0\n";continue;}
		t3=t1;
		for(int i=1;i<=n;i++){
			int it=t1.find(s1[i]);
			//cout<<"it "<<it<<"\n";
			if(it!=-1){
				for(int j=0;j<s2[i].size();j++)t1[j+it]=s2[i][j];
				//cout<<t1<<" "<<t2<<"\n";
			}
			if(t1==t2)ans++;
			t1=t3;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
