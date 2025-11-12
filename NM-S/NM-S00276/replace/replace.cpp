#include<bits/stdc++.h>
using namespace std;
int n,q;
struct th{
	string a,b;
}l[205];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>l[i].a>>l[i].b;
	}
	string a,b;
	for(int i=0;i<q;i++){
		cin>>a>>b;
		bool f=0;
		for(int i=0;i<n;i++){
			if(l[i].a==a && l[i].b==b){
				cout<<1<<"\n";
				f=1;
				break;
			}
		}
		if(!f)cout<<0<<"\n";
	}
	return 0;
}
