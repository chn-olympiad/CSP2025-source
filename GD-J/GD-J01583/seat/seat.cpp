#include <bits/stdc++.h>
using namespace std;
int a[1000000],n,m,p,p1;
void aaa(int l,int r){
	int l1=l;
	int r1=r;
	int mid=(a[l]+a[r])/2;
	while(l<=r){
		while(a[l]>mid) l++;
		while(a[r]<mid) r--;
		if(l<=r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}
	if(l1<r) aaa(l1,r);
	if(r1>l) aaa(l,r1);
}
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	fin>>n>>m;
	for(int i=1;i<=n*m;i++) fin>>a[i];
	p1=a[1];
	aaa(1,n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p1) p=i;
	}
	if(p%n==0){
		fout<<p/n<<" ";
		if((p/n)%2==0) fout<<1;
		else fout<<n;
	}
	else{
		fout<<p/n+1<<" ";
		if((p/n+1)%2==0) fout<<n-p%n+1;
		else fout<<p%n;
	}
	return 0;
}
