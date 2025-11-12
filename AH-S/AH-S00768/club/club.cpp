#include<bits/stdc++.h>
using namespace std;
long long t;
struct node{
	long long a,b,c;
}
bool cmp(node x,node y){
	if(x.a!=y.a){
		return x.a>y.a;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=n;i++){
		long long n;
		cin>>n;
		node s;
		for(int j=1;j<=n;j++){
			cin>>s[j].a>>s[j].b>>s[j].c;
		}
		sort(s+1,s+n+1,cmp);
	}
}
