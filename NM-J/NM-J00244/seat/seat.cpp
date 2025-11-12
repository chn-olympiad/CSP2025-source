#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int n,m,ls,sum=1,aa[110];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>aa[i];
	}
	ls=aa[1];
	sort(aa+1,aa+1+n*m,cmp);
	for(int i=1; i<=n*m; i++)
		if(aa[i]==ls) {
			ls=i;
			break;
		}
	while(ls-2*n>=0) {
		ls-=2*n;
		sum+=2;
	}
	if(ls>n) {
		ls-=n;
		ls=n-ls+1;
		sum+=1;
	}
	if(ls==0)ls=1;
	cout<<sum<<" "<<ls;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
