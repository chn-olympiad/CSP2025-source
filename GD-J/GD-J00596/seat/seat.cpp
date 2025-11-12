#include<bits/stdc++.h>
using namespace std;
struct st {
	int s;
	bool f;
} stu[200];
bool cmp(st x,st y) {
	return x.s>y.s;
}
int n,m,p=0;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n*m; i++) {
		cin>>stu[i].s;
		if(i==0) stu[i].f=true;
		else stu[i].f=false;
	}
	sort(stu,stu+(n*m),cmp);
	for(int i=0; i<m; i++) {
		if(i%2==0) {
			for(int j=0; j<n; j++,p++) {
				if(stu[p].f==true) {
					cout<<i+1<<' '<<j+1<<endl;
					return 0;
				}
			}
		} else {
			for(int j=n-1; j>=0; j--,p++) {
				if(stu[p].f==true) {
					cout<<i+1<<' '<<j+1<<endl;
					return 0;
				}
			}
		}
	}
}
