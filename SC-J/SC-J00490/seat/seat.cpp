#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; cin>>n>>m;
	int r_grade,seat;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r_grade=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r_grade){
			seat=i;
		}
	}
	int op;
	if(seat%n==0) op=seat/n;
	else op=seat/n+1;
	int ad=seat%n;
	if(op%2==0) cout<<op<<" "<<n+1-ad;
	else if(op%2==1){
		if(ad==0) cout<<op<<" "<<n;
		else cout<<op<<" "<<ad; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 