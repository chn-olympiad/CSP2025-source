#include<bits/stdc++.h>
using namespace std;
long long n,m,sit_by;
long long answer=0;
long long a[200]; 

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	long long fans=a[1];
	sort(1+a,1+a+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==fans){
			sit_by=i;
			break;
		}
	}
//	for(long long i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	} 
	//cout<<endl<<sit_by<<endl<<fans<<endl;
	long long hang=0;
	long long lie=(sit_by-1)/n+1;
	if(lie%2==0){
		hang=n-(sit_by-1)%n;
	}
	else{
		hang=(sit_by-1)%n+1;
	}
	printf("%lld %lld",lie,hang);
	return 0;
}
