#include<bits/stdc++.h>
using namespace std;
int n,m=1;
struct nd{
	int num;
	int id;
}a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	for(int i=2;i<=k;i++){
		for(int j=k;j>=i;j--){
			if(a[j].num>a[j-1].num){
				swap(a[j].num,a[j-1].num);
				swap(a[j].id,a[j-1].id);
			}
		}
	}
	int p;
	for(int i=1;i<=k;i++){
		if(a[i].id==1){
			p=i;
		}
	}
	int b,c;
	b=p/n;
	c=p%n;
	if(c==0){
		if(b%2==0){
			cout<<b<<' '<<1;
		}else{
			cout<<b<<' '<<n;
		}
	}else{
		if(b%2==0){
			cout<<b+1<<' '<<c;
		}else{
			cout<<b+1<<' '<<n-c+1;
		}
	}
	return 0;
}



