#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i = 1;i<=(n*m);i++){
		cin>>a[i];
	}
	
	int accepted = a[1];
	
	sort(a+1,a+(n*m)+1,cmp);
	
	int l,r;
	l = 1;
	r = n*m;
	int mid;
	bool flag = false;
	while(l<r){
		mid = (l+r)/2;
		if(a[mid] == accepted){
			break;
			flag = true;
		}
		else if(a[mid]>accepted){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	if(a[mid] == accepted) ;
	else if(a[l] == accepted) mid = l;
	
	int ans1,ans2;
	
	int c = mid%(2*n);
	
	if(n==1){
		cout<<mid<<" "<<1<<endl;
		return 0;
	}
	if(m==1){
		cout<<1<<" "<<mid<<endl;
		return 0;
	}
	
	if(c==0){
		ans1 = mid/n;
		ans2 = 1;
	}
	else{
		int b = mid/(2*n)+1;
		if(c<=n){
			ans1 = 2*(b-1)+1;
			ans2 = c;
		}
		else{
			ans1 = 2*(b-1)+2;
			ans2 = n-(c-n)+1;
		}
	}
	
	cout<<ans1<<" "<<ans2<<endl;
	
	return 0;
}