#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string a,b;
};
int sum;
node a[500005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	for(int i=1;i<=q;i++){
		sum=0;
		string from,to;
		cin>>from>>to;
		for(int i=1;i<=n;i++){
			if(from.find(a[i].a)==string::npos) continue;
			else{
				int x=from.find(a[i].a);
				string pre="",nxt="";
				for(int j=0;j<x;j++) pre+=from[j];
				for(int j=x+a[i].b.size();j<from.size();j++) nxt+=from[j];
				string ans=pre+a[i].b+nxt;
				if(ans==to) sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}

