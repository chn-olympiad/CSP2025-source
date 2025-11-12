#include<iostream>
#include<string>
using namespace std;
const int N=2e5+15;
int n,q;
struct node{
	string s1,s2;
}str[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>str[i].s1>>str[i].s2;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			int len=str[i].s1.size();
			for(int j=0;j+len<=t1.size();j++){
				string tmp1=t1,tmp2=t2;
				tmp1.replace(j,len,str[i].s2);
				if(tmp1==tmp2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
