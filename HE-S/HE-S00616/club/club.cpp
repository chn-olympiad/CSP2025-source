#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t;

int n;

int cnta,cntb,cntc;

int con;

long long ans;

struct node{
	int a;
	int b;
	int c;
	int maxn;
}d[N];

bool cmp(node a,node b){
	return a.maxn > b.maxn;
}

void check2(int a,int b) {
	if (a>b){
		ans+=a;
		cntb++;
	}

	else {
		ans+=b;
		cntc++;
	}
}

void check(int a,int b,int c){
//	cout << cnta << " " << cntb << " " << cntc << '\n';
	if (cnta == con || cntb == con || cntc == con){
		if (cnta == con){
			check2(b,c);
		}
		else if(cntb == con) {
			if (a>c){
				ans+=a;
				cnta++;
			}

			else {
				ans+=c;
				cntc++;
			}
		}
		else if(cntc == con) {
			if (a>b){
				ans+=a;
				cnta++;
			}

			else {
				ans+=b;
				cntb++;
			}
		}
	}
	else{
		if (a > b && a > c && cnta<con) {
			cnta++;
			ans+=a;
		}

		else if (b>a && b>c && cntb<con){
			cntb++;
			ans+=b;
		}

		else if (c>a && c>b && cntc<con){
			cntc++;
			ans+=c;
		}
	}	
}

int main() {
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while(t--) {

		cnta=cntb=cntc=0;
		ans = 0;
		cin >> n;
		con = n/2;

		for (int i = 1 ; i <= n ; i ++) {
			cin >> d[i].a >> d[i].b >> d[i].c ;
			d[i].maxn = max({d[i].a , d[i].b , d[i].c});
//			cout << d[i].maxn  << " " << "sbdp" << '\n';
		}
		sort(d+1,d+1+n,cmp);

		for(int i = 1 ; i <= n ; i ++) {
			check(d[i].a , d[i].b , d[i].c);
		}
		cout << ans << '\n';
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
