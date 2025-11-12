#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct str{
	long long f;
	long long num;
}a[120];
bool cmp(str x,str y){
	return x.f>y.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	long long nm=n*m;
	for(long long i=1;i<=nm;i++){
		cin>>a[i].f;
		a[i].num=i;
	}
	sort(a+1,a+nm+1,cmp);
	long long ain=0;
	for(long long i=1;i<=nm;i++){
		if(a[i].num==1){
			ain=i;
			break;
		}
	}
	long long asd=ain/n;
	long long lkj=(ain-1)%n;
	if(ain%n!=0){
		asd+=1;
	}
	cout<<asd;
	if(asd%2==0){
		cout<<' '<<n-lkj;
	}
	else{
		cout<<' '<<lkj%n+1;
	}
	
	
	return 0;
}
