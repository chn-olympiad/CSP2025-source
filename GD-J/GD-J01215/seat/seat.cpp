#include<bits/stdc++.h>
using namespace std;
const int N=105;
int alr,rlw;
int a[N];
int id;
int n,m;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	alr=rlw=1;
	for(int i=2;i<=n*m;i++) {
		cin>>a[i];
		if(a[i]>a[1]) {
			if(alr%2) {
				rlw++;
				if(rlw==n+1) alr++,rlw=n; 
			} else {
				rlw--;
				if(rlw==0) alr++,rlw=1;
			}
		}
	}
	cout<<alr<<" "<<rlw;
}
//机会总是留给有准备的人的
//而你，J T2 造数据人，你不用准备
//因为你没有机会 
