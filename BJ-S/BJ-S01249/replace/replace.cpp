#include<bits/stdc++.h>
using namespace std;
string a[200010],c[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		string nz1,nz2;
		int cnt=0;
		int b,e;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				b=i;
				break;
			}
		}
		for(int i=x.size()-1;i>=0;i--){
			if(x[i]!=y[i]){
				e=i;
				break;
			}
		}
		for(int i=b;i<=e;i++){
			nz1+=x[i];
			nz2+=y[i];
		}
		for(int i=1;i<=n;i++){
			if(x.find(a[i])&&a[i].find(nz1)&&y.find(c[i])&&c[i].find(nz2)){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
