#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int n,m,a[105],s,si,o,p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
;		if(a[i]==s) {
			si=i;
			break;
		}
	}
	o=ceil(si*1.0/n);
	if(o%2==1){
		p=si%m;
		if(p==0) p=m;
	}else{
		p=si%m;
		p=m+1-p;  
		if(p==m+1) p=1;
	}
	cout << o << " " << p; 
	return 0;
}

