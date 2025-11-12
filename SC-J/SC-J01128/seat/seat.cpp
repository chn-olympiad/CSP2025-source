#include<bits/stdc++.h>
using namespace std;
long long n,m,mn;
long long a[110];
long long rg,ri,ct=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	mn=m*n;
	for(long long i=1;i<=mn;++i){
		cin>>a[i];
	}
	rg=a[1];
	sort(a+1,a+mn+1);
	reverse(a+1,a+mn+1);
	for(long long i=1;i<=mn;++i){
		if(a[i]==rg){
			ri=i;	
		}
	}
	
	//开始模拟
	long long h=1,l=1;
	bool dr=1;
	while(ct!=ri-1){
		if(dr)++h;
		else --h;
		if(h==n+1){
			--h;
			dr=!dr;
			++l;
		}
		if(h==0){
			++h;
			dr=!dr;
			++l;
		}
		++ct;
	}
	cout<<l<<' '<<h;
	return 0;
}