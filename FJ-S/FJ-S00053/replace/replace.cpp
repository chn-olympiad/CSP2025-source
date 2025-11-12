#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
string a[10001],b[10001],x,y,f,g;
inline bool check(int u,int v){
//	cout<<"W0\n";
	for(int i=0;i<v;i++){
		if(x[i]!=y[i])return 0;
	}
//	cout<<"W1\n";
	for(int i=0;i<a[u].size();i++){
		if(a[u][i]!=x[v+i])return 0;
	}
//	cout<<"W2\n";
	for(int i=0;i<b[u].size();i++){
		if(b[u][i]!=y[v+i])return 0;
	}
//	cout<<"W3\n";
	for(int i=v+a[u].size();i<x.size();i++){
		if(x[i]!=y[i-a[u].size()+b[u].size()])return 0;
	}
//	cout<<"W4\n";
	return 1;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i]>>b[i];
	for(int i=1; i<=m; i++) {
		sum=0;
		cin>>x>>y;
		for(int j=1; j<=n; j++) {
//			cout<<i<<" "<<j<<" "<<a[j].size()<<" "<<x.size()<<" "<<b[i].size()<<" "<<y.size()<<endl;
			if(a[j].size()+x.size()==y.size()+b[j].size()&&a[j].size()<=x.size()) {
//				puts("Yes");
				for(int k=0; k<=x.size()-a[j].size(); k++) {
//					cout<<i<<" "<<j<<" "<<k<<" "<<x.size()<<" "<<a[j].size()<<"???"<<x.size()-a[j].size()<<endl;
					if(check(j,k)){
						sum++;
//						cout<<i<<" "<<j<<" "<<k<<endl;
						break;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
nei cun:
2048 MiB
yong gang qu zuo !
----form luogu joe303
*/
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
