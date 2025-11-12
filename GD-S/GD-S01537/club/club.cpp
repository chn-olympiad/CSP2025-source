#include <bits/stdc++.h>
using namespace std;
const int N=12e4;
long long T,n,u,v,w,l1,l2,l3,ans,a1,a2,a3;
priority_queue<int,vector<int>,greater<int> > s1,s2,s3,cl;
int main() {
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>T;
	while (T--) {
		cin >>n;
		ans=l1=l2=l3=0;
		s1=s2=s3=cl;
		for (int i=1;i<=n;i++) {
			cin >>a1 >>a2 >>a3;
			if (a1>=a2 && a1>=a3) {
				l1++;
				ans+=a1;
				if (a2>=a3) {
					s1.push(a1-a2);
				} else {
					s1.push(a1-a3);
				}
			} else if (a2>=a1 && a2>=a3) {
				l2++;
				ans+=a2;
				if (a1>=a3) {
					s2.push(a2-a1);
				} else {
					s2.push(a2-a3);
				}
			} else if (a3>=a2 && a3>=a1) {
				l3++;
				ans+=a3;
				if (a2>=a1) {
					s3.push(a3-a2);
				} else {
					s3.push(a3-a1);
				}
			}
		}
		if (l1>n/2) {
			for (;l1>n/2;l1--) {
				ans-=s1.top();
				s1.pop();
			}
		} else if (l2>n/2) {
			for (;l2>n/2;l2--) {
				ans-=s2.top();
				s2.pop();
			}
		} else if (l3>n/2) {
			for (;l3>n/2;l3--) {
				ans-=s3.top();
				s3.pop();
			}
		}
		cout <<ans <<"\n";
	}
	return 0;
}

