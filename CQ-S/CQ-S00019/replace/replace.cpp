#include<bits/stdc++.h>
using namespace std;
struct node{
	string x,y;
}a[200005];
int b[200005];
map<string,string> dic;
string x,y,z;
int n,m,len;
int le,ri;
int sum=0;
void dfs(){
	string ll="",ll2="";
	for (int i=1;i<=len;i++){
		for (int l=0;l+b[i]-1<x.size();l++){
			if (le<l||l+b[i]-1<ri){
				continue;
			}
			ll="";
			ll2="";
			for (int j=l;j<l+b[i];j++){
				ll.push_back(x[j]);
				ll2.push_back(y[j]);
			}
			if (dic[ll]==ll2){
				sum++;
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		dic[a[i].x]=a[i].y;
		b[i]=a[i].x.size();
	}
	len=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=m;i++){
		cin>>x>>y;
		le=-1,ri=x.size();
		while(x[le+1]==y[le+1]){
			le++;
		}
		while(x[ri-1]==y[ri-1]){
			ri--;
		}
		le++;
		ri--;
		sum=0;
		dfs();
		cout<<sum<<endl;
	}
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
