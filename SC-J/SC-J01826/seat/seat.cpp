#include <bits/stdc++.h>
using namespace std;
long long n,m;
struct pp{
	long long z,c;	
}A[20000];
bool cmp(pp x,pp y){
	return x.z>y.z;
}
long long l(long long x) {
	if(x%m!=0){
		return x/m+1;
	}else{
		return x/m;
	}
}
long long h(long long x){
	if(l(x)%2==0){
		if(x%m==0){
			return m-(x%m);
		}
		return m-(x%m)+1;
	}else{
		if(x%m==0){
			return m;
		}
		return x%m;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>A[i].z;
		A[i].c=i;
	}
	sort(A+1,A+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(A[i].c==1){
			cout<<l(i)<<" "<<h(i);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
