#include <bits/stdc++.h>
using namespace std;
struct op {
	int a;//
	int b;//   /5 3 4    /4 2 1   3 5 1   3 2 4
	int c;
} s[100005];
int p;
int p1;
int p2;
int n;
int add(op a,op b) {
	if(p<=n/2&&a.a!= b.a) {
	 p++;
		return a.a>b.a;
	} else if(p1<=n/2&&a.b!=b.b)
	{
		p1++;
		return a.b>b.b;
	}
	else if(p2<=n/2&&a.c!=b.c) {
		p2++;
		return a.c>b.c;
	}
return a.a>b.a;

}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {

		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
	sort(s,s+n-1,add);
	int l=0;
	for(int i=0;i<n;i++){
		l+=max(s[i].a,max(s[i].b,s[i].c));
	}

	cout<<l;





	}






return 0;
}
