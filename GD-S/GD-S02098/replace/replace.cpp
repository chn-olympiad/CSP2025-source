#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
long long p=9e10;
int n,q;
string s[N][3];
map<string,int>mp;
string mkp(int x,int y){
	string s="";
		if(x<0)s+='-';
		else s+='+';
		s+=to_string(abs(x));
		if(y<0)s+='-';
		else s+='+';
		s+=to_string(abs(y));
	return s;
}
bool check(string x,string y,int i){
	int xx=x.find(s[i][1]),yy=y.find(s[i][2]);
	if(xx>p||yy>p)return 0;
	if(xx!=yy)return 0;
//	a.erase(xx,s[i][1].size());
//	b.erase(yy,s[i][2].size());
//	if(x!=y)return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		s[i][1]=x,s[i][2]=y;
		int px=x.find('b')-1,fx=x.size()-x.find('b');
		int py=y.find('b')-1,fy=y.size()-y.find('b');
		mp[mkp(px-py,fx-fy)]++;		
	}
	if(q==1){
		string x,y;
		int cnt=0;
		cin>>x>>y;	
		for(int i=1;i<=n;i++){
			if(check(x,y,i)){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;			
	}
	else{
		while(q--){
			string x,y;
			cin>>x>>y;
			int px=x.find('b')-1,fx=x.size()-x.find('b');
			int py=y.find('b')-1,fy=y.size()-y.find('b');
			cout<<mp[mkp(px-py,fx-fy)]<<'\n';
		}
		
	}

	return 0;
} 
