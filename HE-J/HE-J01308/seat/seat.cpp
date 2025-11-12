#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+1+(n*m),cmp);
	int s1=1,s2=1;
	for(int i=1;i<=q;i++) {
		while(s2<=m) {
			s1++;
			if(s1>n) {
				s2++;
				s1--;
			}
		}
		
	}
	cout<<s2<<" "<<s1;
	return 0;
}

