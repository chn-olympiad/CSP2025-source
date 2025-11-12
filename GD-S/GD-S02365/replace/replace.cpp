#include<iostream>
#include<string>
using namespace std;
string s1[200005],s2[200005];
int l1[200005],l2[200005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l1[i]=s1[i].size();
		l2[i]=s2[i].size();
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int id=0;
			while(t1.find(s1[i],id)!=string::npos){
				id=t1.find(s1[i],id);
				string t3=t1;
				t3.erase(id,l1[i]);
				t3.insert(id,s2[i]);
				if(t3==t2) ans++;
				id++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
