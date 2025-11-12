#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
struct person {
	int a,b,c;
	int st,nd,rd;
	int val;
};
bool cmp(person x,person y) {
	return x.val>y.val;
}
person a[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		memset(a,0,sizeof a);
		int n,ans=0;
		int cnta=0,cntb=0,cntc=0;
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>a[i].a;
			cin>>a[i].b;
			cin>>a[i].c;
			a[i].st=max(a[i].a,max(a[i].b,a[i].c));
			a[i].rd=min(a[i].a,min(a[i].b,a[i].c));
			a[i].nd=a[i].a+a[i].b+a[i].c-a[i].st-a[i].rd;
			a[i].val=a[i].st-a[i].nd;
		}
		sort(a,a+n,cmp);
		for(int i=0; i<n; i++) {
			if(a[i].st==a[i].a) {
				if(cnta<n/2) {
					cnta++;
					ans+=a[i].st;
				}
				else{
					ans+=a[i].nd;
				} 
			}
			else if(a[i].st==a[i].b) {
				if(cntb<n/2) {
					cntb++;
					ans+=a[i].st;
				}
				else{
					ans+=a[i].nd;
				} 
			}
			else if(a[i].st==a[i].c) {
				if(cntc<n/2) {
					cntc++;
					ans+=a[i].st;
				}
				else{
					ans+=a[i].nd;
				} 
			}
		}
		cout<<ans<<endl;
	}
}
