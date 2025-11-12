#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int n,ans;
struct node {
	long long a,b,c;
}cb[1000005];
struct nodee {
	long long a,b;
}cbb[1000005];
bool cmp (node a,node b){
	return a.a>b.a;
}
bool cmp2 (node a,node b){
	return a.a-a.b>b.a-b.b;
}
bool cmp3 (nodee a,nodee b){
	return a.a-a.b>b.a-b.b;
}
void work1(int x1,int x2,int x3,int sum,int i){
	if (x1>n/2||x2>n/2||x3>n/2) return ;
	else if (i==n+1) {
		ans=max(ans,sum);
		return ;
	}
	work1(x1+1,x2,x3,sum+cb[i].a,i+1);
	work1(x1,x2+1,x3,sum+cb[i].b,i+1);
	work1(x1,x2,x3+1,sum+cb[i].c,i+1);
}
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while (t--){
		cin >>n;
		ans=0;
		int cb2=0,cb3=0;
		for (int i=1;i<=n;i++){
			cin >>cb[i].a>>cb[i].b>>cb[i].c;
			if (cb[i].b==0) cb2++;
			if (cb[i].c==0) cb3++;
		}
		if (n<=25){
			work1(0,0,0,0,1);
			cout <<ans<<endl;
			return 0;
		}
		if (cb2==n&&cb3==n){
			sort(cb+1,cb+1+n,cmp);
			for (int i=1;i<=n/2;i++)
				ans+=cb[i].a;
			cout <<ans<<endl;
			return 0;
		}
		long long sum=0;
		if (cb3==n){
			sort(cb+1,cb+1+n,cmp2);
			for (int i=1;i<=n/2;i++)
				sum+=cb[i].a;
			for (int i=n/2+1;i<=n;i++)
				sum+=cb[i].b;
			cout <<sum<<endl;
			return 0;
		}
		for (int i=1;i<=n;i++){
			if (cb[i].a<=cb[i].b&&cb[i].a<=cb[i].c) cbb[i].a=cb[i].b,cbb[i].b=cb[i].c;
			if (cb[i].b<=cb[i].a&&cb[i].b<=cb[i].c) cbb[i].a=cb[i].a,cbb[i].b=cb[i].c;
			if (cb[i].c<=cb[i].b&&cb[i].c<=cb[i].a) cbb[i].a=cb[i].a,cbb[i].b=cb[i].b;
		}
		sort(cbb+1,cbb+1+n,cmp3);
		for (int i=1;i<=n/2;i++)
			sum+=cbb[i].a;
		for (int i=n/2+1;i<=n;i++)
			sum+=cbb[i].b;
		cout <<sum<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
