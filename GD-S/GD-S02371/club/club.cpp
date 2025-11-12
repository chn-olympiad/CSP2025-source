#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+10;

struct Node{
	int a, b, c, l1, l2, s1, s2;
}m[N];

bool cmp1(const Node& n1, const Node& n2){
	return n1.l1<n2.l1;
}

bool cmp2(const Node& n1, const Node& n2){
	return n1.l2<n2.l2;
}

int n;

int solve(){
	int ans = 0;
	cin >> n;
	int A=0, B=0, C=0;
	for(int i=1;i<=n;i++){
		cin >> m[i].a >> m[i].b >> m[i].c;
		int a = m[i].a, b = m[i].b, c = m[i].c;
		if(a>b&&a>c){
			A++;
			if(b<c) {
				swap(b, c);
				m[i].s1 = 3;
				m[i].s2 = 2;
			} else {
				m[i].s1 = 2;
				m[i].s2 = 3;
			}
		} else if(b>a&&b>c){
			B++;
			swap(a, b);
			if(b<c) {
				swap(b, c);
				m[i].s1 = 3;
				m[i].s2 = 1;
			} else {
				m[i].s1 = 1;
				m[i].s2 = 3;
			}
		} else {
			C++;
			swap(a, c);
			if(b<c) {
				swap(b, c);
				m[i].s1 = 2;
				m[i].s2 = 1;
			} else {
				m[i].s1 = 1;
				m[i].s2 = 2;
			}
		}
		m[i].l1 = a-b;
		m[i].l2 = b-c;
		ans+=a;
	}
	sort(m+1, m+n+1, cmp1);
	int cnt = 1;
	bool flag = 1;
	while(A>n/2) {
		flag = 0;
		ans -= m[cnt].l1;
		B+=(m[cnt].s1==2);
		C+=(m[cnt].s1==3);
		A--, cnt++;
	}
	if(flag){
		while(B>n/2) {
			flag = 0;
			ans -= m[cnt].l1;
			A+=(m[cnt].s1==1);
			C+=(m[cnt].s1==3);
			B--, cnt++;
		}
	}
	if(flag){
		while(C>n/2) {
			flag = 0;
			ans -= m[cnt].l1;
			A+=(m[cnt].s1==1);
			B+=(m[cnt].s1==2);
			C--, cnt++;
		}
	}
	sort(m+1, m+n+1, cmp2);
	cnt = 1;
	flag = 1;
	while(A>n/2) {
		flag = 0;
		ans -= m[cnt].l2;
		B+=(m[cnt].s2==2);
		C+=(m[cnt].s2==3);
		A--, cnt++;
	}
	if(flag){
		while(B>n/2) {
			flag = 0;
			ans -= m[cnt].l2;
			A+=(m[cnt].s2==1);
			C+=(m[cnt].s2==3);
			B--, cnt++;
		}
	}
	if(flag){
		while(C>n/2) {
			flag = 0;
			ans -= m[cnt].l2;
			A+=(m[cnt].s2==1);
			B+=(m[cnt].s2==2);
			C--, cnt++;
		}
	}
//	printf("%lld %lld %lld\n", A, B, C);
	return ans;
}

signed main(){
	ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int TASKS;
	cin >> TASKS;
	while(TASKS--) {
		cout << solve() << '\n';
	}
	
	return 0;
}
