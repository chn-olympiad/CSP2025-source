#include<bits/stdc++.h>
using namespace std;
struct stu{
	int id,num,c,r;
	bool operator<(const stu other)const{
		return num>other.num;
	}
}a[105];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1);
	a[1].c=1,a[1].r=1;
	for(int i=2;i<=n*m;i++){
		if(i%n==1){
			a[i].c=a[i-1].c+1,a[i].r=a[i-1].r;
			if(a[i].id==1){
				cout<<a[i].c<<" "<<a[i].r;
				return 0;
			}
		}
		else{
			if(a[i-1].c%2==1){
				a[i].c=a[i-1].c,a[i].r=a[i-1].r+1;
				if(a[i].id==1){
					cout<<a[i].c<<" "<<a[i].r;
					return 0;
				}
			}
			else{
				a[i].c=a[i-1].c,a[i].r=a[i-1].r-1;
				if(a[i].id==1){
					cout<<a[i].c<<" "<<a[i].r;
					return 0;
				}
			}
		}
	}
	return 0;
}

