#include<iostream>
using namespace std;
string s[10003][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	bool flag=false;
	int Max=0;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int len=s[i][1].length();
		Max=max(Max,len);
		if(s[i][1][0]=='B' || s[i][2][0]=='B') flag=true;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int a=t1.find("B");
		int b=t2.find("B");
		if(a==b){
			cout<<0<<'\n';
			continue;
		} else{
			if(t1[0]=='B' || t2[0]=='B'){
				if(flag) cout<<2<<'\n';
				else cout<<0<<'\n';
				continue;
			}
			if(abs(a-b)>Max) cout<<2<<'\n';
			else cout<<1<<'\n';
		}
	}
	return 0;
}
