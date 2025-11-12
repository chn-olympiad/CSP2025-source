#include <iostream>
#include <cstdio>
using namespace std;
struct q{
	int a;
	int num;
};
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	q a[105];
	for(int i=0;i<n*m;i++){
		cin>>a[i].a;
		a[i].num=i+1;
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;j<(n*m)-1;j++){
			if(a[j].a<a[j+1].a){
				swap(a[j],a[j+1]);
			}
		}
	}
	int num=0;
	for(int i=0;i<n*m;i++){
		if(a[i].num==1){
			num=i+1;
		}
	}
	cout<<(num-1)/(n)+1<<' ';
	if(((num-1)/(n))%2==0){
		cout<<(num-1)%(n)+1;
	}else{
		cout<<n-((num)%(n)-1);
	}
	return 0;
}