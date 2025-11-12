#include <bits/stdc++.h>
using namespace std;
long long a[1005];
long long r,m,n,score,ansn,ansm;
int main()
{
	cin.tie(0);cout.tie(0);
	int n1,m1;
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin >> n >> m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin >> a[i];
	}
	r=a[1];
	for(int i=1;i<=num;i++){
		for(int j=i+1;j<=num;j++){
			if(a[i]<a[j]){
				swap(a[j],a[i]);
			}
		}
	}
	for(int i=1;i<=num;i++){
		if(a[i]==r) score=i;
	}
	if(score%m==0) ansm=score/m;
	else ansm=score/m+1;
	if(score%m==0){
		n1=n;
	}
	else {
		n1=score%m;
	}
	if(ansm%2==1) ansn=n1;
	else ansn=n-n1+1;
	cout << ansm << " " << ansn;
	return 0;
}
