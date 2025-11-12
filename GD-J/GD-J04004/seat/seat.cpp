#include <bits/stdc++.h>
using namespace std;
struct stu{
	int rp,isr;
}s[25100];
bool cmp(stu a,stu b){
	return a.rp>b.rp;
}
int x,y,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>s[i].rp;
	s[1].isr=1;
	sort(s+1,s+n*m+1,cmp);
	int qwq=1;
	while(!s[qwq].isr) qwq++;
	x=qwq;
	y=x/n;
	p=x%n;
	//cout<<x<<' '<<y<<' '<<p<<endl;
	if(p!=0)
		y++;
	else p=n;
	//cout<<x<<' '<<n-p+1<<' '<<p<<endl;
	if(y%2==0) {
		int tm=p;
		p=n-tm+1;
		//cout<<"yes"<<endl;
	}
	cout<<y<<' '<<p;
	fclose(stdin);fclose(stdout);
	return 0;
} 
//luogu£º£¨I forgot that, maybe 1057454£©Rr'haril 
