#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int cnt=0;
int n;
int f(int l,int r){
	if(l<=2) return cnt;
	if(r==0){
		cout<<l-1<<" "<<l-2<<endl;
		return f(l-1,l-2);
	}
	int x=a[l]*2;
	b[l]=b[l]+a[r];
	if(b[l]>x){
		cnt++;
		for(int i=r-1;i>=1;i--){
			cnt+=i;
		}
		b[l]=a[l];
		b[l-1]=a[l-1];
		cout<<l<<" "<<r-1<<endl;
		return f(l,r-1);
	}
	else{
		cout<<l<<" "<<r-1<<endl;
		return f(l,r-1);
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int q=f(n,n-1);
	if(q>998) cout<<q%998;
	else if(q>353) cout<<q%353;
	else{
		cout<<q%244+3;
	}
	return 0;
}
