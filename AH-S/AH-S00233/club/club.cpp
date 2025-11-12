#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct Pair{
	int a;
	int b;
};

bool compare2(Pair a, Pair b) {
	return a.a < b.a;
}
int max(int a,int b){
	return a>b?a:b;
}

int main() {

	freopen("club.in", "r", stdin);                                           
	freopen("club.out", "w", stdout);                                         
	int t;
	cin>>t;
	for(int idd=0;idd<t;idd++) {
		int n;
		cin>>n;
		int a1[n], a2[n], a3[n];
		int count2 = 0;
		int count3 = 0;
		for(int i=0;i<n;i++) {
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i] == 0) count2++;
			if(a3[i] == 0) count3++;
		}
		if(n==2){
			int res1 = max(a1[0] + a2[1], a1[0] + a3[1]);
			int res4 = max(a1[1] + a3[0], a1[1] + a2[0]);
			int res5 = max(a2[0] + a3[1], a2[1] + a3[0]);
			cout<<max(res1, max(res4, res5));
		} else if(count2 == n) {
			sort(a1, a1+n);
			int ans = 0;
			for(int i=n-1;i>=n/2;i--) {
				ans += a1[i];
			}
			cout<<ans<<endl;
		} else if(count3 == n) {
			Pair pairs[n];
			for(int i=0;i<n;i++) {
				pairs[i].a = a1[i] - a2[i];
				pairs[i].b = a2[i];
			}
			sort(pairs, pairs+n, compare2);
			int ans = 0;
			for(int i=n-1;i>=n/2;i--) {
				ans += pairs[i].a+pairs[i].b;
			}
			for(int i=n/2-1;i>=0;i--) {
				ans += pairs[i].b;
			}
			cout<<ans<<endl;
		} else {
			int ans = 0;
			for(int i=0;i<n;i++) {
				ans += max(a1[i], max(a2[i], a3[i]));
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}



