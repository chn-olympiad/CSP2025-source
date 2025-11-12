#include<iostream>
#include<algorithm>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int n,ca,cb,cc,ans;
struct node {
	int a,b,c;
}A[100005],B[100005],C[100005];
int cmpA(node q,node w) {
	return min(q.a-q.b,q.a-q.c)<min(w.a-w.b,w.a-w.c);
}
int cmpB(node q,node w) {
	return min(q.b-q.a,q.b-q.c)<min(w.b-w.a,w.b-w.c);
}
int cmpC(node q,node w) {
	return min(q.c-q.a,q.c-q.b)<min(w.c-w.a,w.c-w.b);
}
void workA() {
	sort(A+1,A+ca+1,cmpA);
	int i=1;
	while(ca*2>n) {
		ans-=A[i].a;
		ans+=max(A[i].b,A[i].c);
		ca--;
		i++;
	}
}
void workB() {
	sort(B+1,B+cb+1,cmpB);
	int i=1;
	while(cb*2>n) {
		ans-=B[i].b;
		ans+=max(B[i].a,B[i].c);
		cb--;
		i++;
	}
}
void workC() {
	sort(C+1,C+cc+1,cmpC);
	int i=1;
	while(cc*2>n) {
		ans-=C[i].c;
		ans+=max(C[i].b,C[i].a);
		cc--;
		i++;
	}
}
void work() {
	cin>>n;
	ca=cb=cc=ans=0;
	for(int i=1,a,b,c;i<=n;i++) {
		cin>>a>>b>>c;
		int m=max(a,max(b,c));
		if(a==m) {
			ans+=a;
			A[++ca]={a,b,c};
		}
		else if(b==m) {
			ans+=b;
			B[++cb]={a,b,c};
		}
		else {
			ans+=c;
			C[++cc]={a,b,c};
		}
	}
	if(ca*2>n) {
		workA();
	}
	else if(cb*2>n) {
		workB();
	}
	else {
		workC();
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t=1;
	cin>>t;
	while(t--) {
		work();
	}
	return 0;
}
