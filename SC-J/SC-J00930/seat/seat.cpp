#include<bits/stdc++.h>
using namespace std;
long long m,n,r,a[109],rseatn,rseatm;
//，成绩为s2n 的考生的座位为第2列第1行,成绩为s2n+1 的考生的座位为第3列第1行，以此类推。
int rr(long long r){//查找名次 
	for(long long i=1;i<=m*n;i++)
		if(a[i]==r) return i;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(long long i=1;i<=m*n;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	r=rr(r);
	rseatm=floor(double(r/n))+1;
	//cout<<(r-1)%n+1<<"  "<<floor(double(r%n))+1<<endl;
	if(rseatm%2==1)
		rseatn=(r-1)%n+1;
	else if(rseatm%2==0)rseatn=n-r%n+1;
	printf("%lld %lld",rseatm,rseatn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}