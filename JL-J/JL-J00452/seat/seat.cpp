#include <bits/stdc++.h>
using namespace std;
long long n,m,stu[100000],num,xr,gra,h,l=1,gr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=0;i<num;i++) cin>>stu[i];
	xr=stu[0];
	sort(stu,stu+num);
	for(int i=0;i<num;i++) if(xr==stu[i]) gra=num-i;
	gr=gra;
	while(gr>n){
		l++;
		gr-=2;
	}
	if(l%2==0) h=n-((gra-1)%n);
	if(l%2==1){
		h=gra%n;
		if(h==0) h=n;
	}
	cout<<l<<" "<<h<<endl;
	return 0;
}
