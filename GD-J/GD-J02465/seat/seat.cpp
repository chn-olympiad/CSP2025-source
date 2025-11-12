#include<bits/stdc++.h>
using namespace std;

struct S{
	long long num;
	long long pm;
}a[110];
long long n,m,r,r_pos;

bool cmp(S x,S y){
	return x.num>y.num;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++) cin>>a[i].num;
	r=a[1].num;
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
//		cout<<a[i].num<<" ";
		if(a[i].num==r){
			r_pos=i;
			a[i].pm=i;
			break;
		}
	}
//	cout<<a[r_pos].pm<<"\n";
	long long lie,hang;
	if(a[r_pos].pm%n==0) lie=a[r_pos].pm/n;
	else lie=a[r_pos].pm/n+1;
//	cout<<lie;
	if(lie%2==1){
		if(a[r_pos].pm%n==0) hang=n;
		else hang=(a[r_pos].pm%n);
	}
	else{
		if(a[r_pos].pm%n==0) hang=1;
		else hang=n-(a[r_pos].pm%n)+1;
	}
	cout<<lie<<" "<<hang;	
	return 0;
} 
