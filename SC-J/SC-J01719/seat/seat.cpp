#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+5;
int n,m;
int grade[N];

class Debug {
public:
	void info (int x) {
		printf("[INFO] %d\n",x);
	}
} debug;

bool cmp(int a,int b) {
	return a>b;
}

int find(int p) {
	int l=1,r=n*m+1,mid;
	while(l<r) {
		mid = (l+r)/2;
		
		if(grade[mid] > p) {
			l=mid+1;
		}
		else if(grade[mid] < p) {
			r=mid;
		}
		else if(grade[mid] == p){
			return mid;
		}
	}
	return mid;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int tgt;
	for(int i=1;i<=n*m;++i) {
		cin>>grade[i];
		if(i==1) tgt = grade[i];
	}
	
	sort(grade+1,grade+n*m+1,cmp);
	
//	for(int i=1;i<=n*m;++i) cout<<grade[i]<<" ";
//	cout<<"\n";
	
	int f = find(tgt);
	
//	debug.info(f);
	
	int column = (f+n-1)/n;
	int line = (f-1)%n+1;
	if(!(column % 2)) {
		// it meant that this number should be joined from down to up
		
		cout<<column<<" "<<n-line+1<<'\n';
	}
	else {
		cout<<column<<" "<<line<<"\n";
	}
	return 0;
}