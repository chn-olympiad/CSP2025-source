#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
struct node{
	string str1,str2;
}a[N];
node change(string x,string y){
	string nowx,nowy;
	int f=0,l=x.size()-1;
	while(x[f]==y[f]) f++;
	while(x[l]==y[l]) l--;
	for(int k=f;k<=l;k++){
		nowx+=x[k];
		nowy+=y[k];
	}
	return (node){nowx,nowy};
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string x,y;
		cin>>x>>y;
		a[i].str1=x;
		a[i].str2=y;
	}
	while(q--){
		string x,y;
		int cnt=0;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0;
			continue;
		}
		for(int i=0;i<n;i++){
			node m=a[i];
			node newm=change(m.str1,m.str2);
			node newk=change(x,y);
			if((x==m.str1&&y==m.str2||x.find(m.str1)&&y.find(m.str2))&&newm.str1==newk.str1&&newm.str2==newk.str2){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
