#include<bits/stdc++.h>
using namespace std;
long long n,m,ps;
long long a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long r,rs=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+rs+1,cmp);
	long long wz=0;
	for(int i=1;i<=n*m;i++){
		wz++;
		if(a[i]==r)break;
	}
	int df,sy;
	df=wz/n;
	sy=wz%n;
	if(df%2==0){
		if(sy==0){
			cout<<df<<" "<<1;
		}else{
			cout<<df+1<<" "<<sy;
		}
	}else{
		if(sy==0){
			cout<<df<<" "<<n;
		}else{
			cout<<df+1<<" "<<n-sy+1;
		}
	}
	return 0;
}
