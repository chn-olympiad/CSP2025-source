#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],f,r,c,w,ans1,ans2;
bool cmp(long long l,long long r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	f=n*m;
	for(int i=1;i<=f;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+f+1,cmp);
	for(int i=1;i<=f;i++){
		if(a[i]==r){
			c=i;
			break;
		}
	}
	ans1=(c+n-1)/n;
	w=c%n;
	if(ans1%2==0){
		ans2=n-w+1;
	}
	else if(c<=n){
		ans2=c;
	}
	else{
		ans2=w;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
