#include<bits/stdc++.h>
using namespace std;
struct node{
	long long data,s,e;
};
bool cmp(node a,node b){
	return a.data>b.data;
}
long long n,m,x,y,firstseat;
node s[1000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >>s[i].data;
		s[i].s=i;
	}
	sort(s+1,s+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		s[i].e=i;
		if(s[i].s==1){
			firstseat=s[i].e;
		}
	}
	long long a,b;
	a=firstseat/n;
	b=firstseat%n;
	if(b==0){
		if(a%2==0){
			cout <<a<<' '<<1;
		}
		else {
			cout <<a<<' '<<m;
		}
	}
	else {
		if(a%2==0){
			cout <<a+1<<' '<<b;
		}
		else {
			cout <<a+1<<' '<<m-b+1;
		}
	}
	return 0;
} 
