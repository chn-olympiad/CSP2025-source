#include<bits/stdc++.h>
using namespace std;
struct node{
	int c,k1,k2;
}a[200005];
int main(){
  	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		a[i].c=s1.size();
		for(int j=0;j<a[i].c;j++){
			if(s1[j]=='b'){
				a[i].k1=j;
			}
			if(s2[j]=='b'){
				a[i].k2=j;
			}
		}
	}
	while(q--){
		string x,y;
		int aa,bb,as=0;
		cin>>x>>y;
		int cc=x.size();
		for(int i=0;i<cc;i++){
			if(x[i]=='b'){
				aa=i;
			}
			if(y[i]=='b'){
				bb=i;
			}
		}
		for(int i=0;i<n;i++){
			if(a[i].k1<=aa && (a[i].c-a[i].k1)<=(cc-aa) && (a[i].k1-a[i].k2)==aa-bb){
				as++;
			}
		}
		cout<<as<<endl;
	}
	return 0;
}
