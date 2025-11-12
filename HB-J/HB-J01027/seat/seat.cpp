#include <bits/stdc++.h>
using namespace std;
struct stu{
	int fs,r;
}a[1009];
bool cmp(stu x,stu y){
	return x.fs>y.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l=0,n_=0,m_=0,p=0;
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i].fs;
		a[i].r=i;
	}
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++){
		if(a[i].r==1){
			p=i;
		}
	}
	if(p%n==0) n_=p/n;
	else n_=p/n+1;
	if(n_%2==1) m_=p-(n_-1)*n;
	else{
		int l_1=(n_-1)*n+1,r_1=n_*n;
		while(l_1<r_1){
			if(l_1>=r_1) break;
			swap(a[l_1],a[r_1]);
			l_1++,r_1--;
		}
		for(int i=(n_-1)*n+1;i<=n_*n;i++){
			if(a[i].r==1){
				m_=i;
				if(m_%n==0) m_=n;
				else m_%=n;
			}
		}
	}
	cout<<n_<<" "<<m_;
	return 0;
}
