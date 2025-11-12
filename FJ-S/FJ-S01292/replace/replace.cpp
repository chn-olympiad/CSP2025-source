#include<bits/stdc++.h>
using namespace std;
int n,q,s[200010],p;
string a[200010],b[2000010],c,d;
void f(string c,string d){
	for(int i=1;i<=n;i++){
		p=c.find(a[i]);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		s[i]=a[i].size();
	}
	for(int i=1;i<=q;i++){
		cin>>c;
		cin>>d;
		f(c,d);
	}
	return 0;
}
