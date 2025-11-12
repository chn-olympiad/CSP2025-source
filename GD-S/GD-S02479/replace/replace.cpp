#include <bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
}s[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	while(q--){
		int cnt=0;
		string x,y,t="",t1="";
		cin>>x>>y;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				t+=x[i];
				t1+=y[i];
			} 
		}
		for(int i=1;i<=n;i++){
			if(s[i].a.find(t)!=string::npos&&s[i].b.find(t1)!=string::npos){
				string k=s[i].a,k1=s[i].b;
				k.erase(k.find(t),t.size());
				k1.erase(k1.find(t1),t1.size());
				if(k==k1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
