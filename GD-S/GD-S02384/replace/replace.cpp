#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200010][3];
string sl[200010][3]; 
void t(int i,string s1,string s2){
	int x=0,y=0;
	bool t=0;
	for(int j=0;j<s1.size();j++){
		if(!t and s1[j]!=s2[j]){
			x=j;
			t=1;
		}
		if(s1[j]!=s2[j]){
			y=j;
		}
	}
	a[i][1]=s1.substr(x,y-x+1);
	a[i][2]=s2.substr(x,y-x+1);
	sl[i][1]=s1.substr(0,x+1);
	sl[i][2]=s2.substr(y+1,s1.size()-y);
}
bool pd(int x,int y){
	string s,s1,s2;
	s=sl[x][y];
	s1=sl[n+1][y];
	s2=s1.substr(0,s1.size()-s.size());
	s=s2+s;
	return s==s1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		t(i,s1,s2);
	}
	while(q--){
		string s,s1;
		long long ans=0;
		cin>>s>>s1;
		t(n+1,s,s1);
		s=a[n+1][1];
		s1=a[n+1][2];
		for(int i=1;i<=n;i++){
			if(s==a[i][1] and s1==a[i][2] and pd(i,1) and pd(i,2)){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
