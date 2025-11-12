#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,r_sc,ri;
int score[110];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int t=n*m;
	for(int i=1;i<=t;i++) {
		scanf("%d",&score[i]);
	}
	r_sc=score[1];
	sort(score+1,score+t+1,cmp);
	for(int i=1;i<=t;i++) {
		if(score[i]==r_sc) {
			ri=i;
		}
	}
	int mo=ri%n;
	r=ri/n;
	if(mo>0) {
		r++;
	}
	if(r%2==0) {
		c=n-mo+1;
		if(c>n) c%=n;
	}
	else {
		if(mo==0) c=n;
		else c=mo;
	}
	cout<<r<<" "<<c;
	return 0;
}