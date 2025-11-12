#include <bits/stdc++.h>
using namespace std;
long long n,q,tot;
string t1,t2;
struct str{
	string first,second;
}num[20005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>num[i].first>>num[i].second;
	while(q--){
		tot=0;
		cin>>t1>>t2;
		string ss="",s3="";
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				ss+=t1[i];
				s3+=t2[i];
			}
		}
		for(int i=0;i<=n;i++){
			if(ss==num[i].first&&s3==num[i].second)tot++;
			else if(t1==num[i].first&&t2==num[i].second)tot++;
		}
		cout<<tot<<endl;
	}
	return 0;
}
