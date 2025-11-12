#include<bits/stdc++.h>
using namespace std;
struct stu{
	int q,c;
}a[110];
bool cmp(stu u,stu v){
	return u.c>v.c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p=1,d=1,n1,m1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].q=p;
		p=0;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].q==1){
			d=i;
		}
	}
	m1=ceil(d*1.0/n);
	if(m1%2==0){
		n1=n-(d-(m1-1)*n)+1;
	}else{
		n1=d-(m1-1)*n;
	}
	cout<<m1<<" "<<n1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
