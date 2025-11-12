#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],num,r=1,c=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
			cin>>a[i];
	num=a[1];
	int k=1;
	sort(a+1,a+1+n*m,cmp);
	if(num==a[1]){
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	for(int i=2; i<=n*m; i++){
		if(k){
			r++;
			if(r>n)
				k=0,r=n,c++;
		}
		else{
			r--;
			if(r<1)
				k=1,r=1,c++;
		}
		//cout<<a[i]<<" "<<c<<" "<<r<<endl;
		if(a[i]==num){
			cout<<c<<" "<<r<<endl;
			break;
		}
	}
	return 0;
}
