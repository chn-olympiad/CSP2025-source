#include <bits/stdc++.h>
using namespace std;

const int tt=1e5+10;
int tmp[10];

struct node{
	int a,b,c;
}f[tt];

bool cmp(node x,node y){
	return x.a>y.a;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>f[i].a>>f[i].b>>f[i].c;
		}
		sort(f+1,f+1+n,cmp);
		int tmp=0,res=0;
		int cnt=0;
		for(int i=1;i<=n/2;i++){
			cnt+=f[i].a;
		}
		for(int i=n/2+1;i<=n;i++){
			cnt+=f[i].b;
		}
		cout <<cnt<<endl;
	}
	return 0;
}
