#include<bits/stdc++.h>
using namespace std;
int sum,l,v,a,b;

struct node{
	string ks,js;
	int cd;
}m[100001];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>m[i].ks>>m[i].js;
	}
	char p[10001],q[10001],x[10001],y[10001];
	for(int i=1;i<=b;i++){
		sum=0;
		cin>>p>>q;
			v=0;
		for(int j=0;j<1000;j++){
			if(p[j]!=q[j]){
				x[v]=p[j];
				y[v]=q[j];
				v++;
			}
		}
		for(int i=1;i<=a;i++){
			if(m[i].ks==x&&m[i].js==y)	sum++;
		} 
		cout<<sum<<endl;
	}

	return 0;
} 
