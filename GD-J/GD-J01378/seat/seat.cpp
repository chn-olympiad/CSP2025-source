#include<bits/stdc++.h>
using namespace std;
long long n,m,ni,mi,myscore,c,r,q;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n:行 m:列 
	long long nm=n*m;
	long long a[nm];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	myscore=a[0];
	sort(a,a+nm,greater<int>());
	for(int i=0;i<nm;i++){
		if(a[i]==myscore){
			q=i;
			break;
		}
	}
	c=q/n+1;//c:在的列 
	r=q%n;//r:在的行
	if(q<m){
		r+=1;
		cout<<c<<' '<<r;
		return 0;
	}
	if(r==0){
		if(q==0){
			r=1;
			cout<<c<<' '<<r;
			return 0;
		}else{
			int ij=q/m;
			if(ij%2==0){
				r=1;
			}else{
				r=m;
			}
			cout<<c<<' '<<r;
			return 0;
		}
	}
	if(r+1>n){
		r=r-n;
	}
	cout<<c<<' '<<r+1;
	return 0;
}
