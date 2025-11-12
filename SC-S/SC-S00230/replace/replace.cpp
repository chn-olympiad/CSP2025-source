#include<bits/stdc++.h>
using namespace std;
int n,q;
map <string,string> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		s[x]=y;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size(),cnt=0;
//		cout<<len<<" ";
		for(int i=1;i<=len;i++){
			for(int j=0;j+i-1<len;j++){
				string y=t1.substr(j,i),y_1="";
				if(s.find(y)!=s.end()) y_1=s[y];
				else continue;
				string re=t1;
				re.replace(j,i,y_1);
//				cout<<re<<" ";
				if(re==t2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
