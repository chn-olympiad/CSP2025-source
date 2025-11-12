#include<bits/stdc++.h>
using namespace std;
int n,m;
struct b{
	int s,num;
}a[110];
bool pd(b s1,b s2){
	return s1.s>s2.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].num=i;
	}
	sort(a+1,a+m*n+1,pd);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			if(i==1){
				cout<<1<<" "<<1;
				break;
			}
			if(i%m==0){
				if(n>m){
					cout<<i/m-1;
				}else if(n==m){
					cout<<i/m;
				}else{
					cout<<i/m+1;
				}
			}else{
				if(n<m){
					cout<<i/m-1;
				}else if(n==m){
					cout<<i/m+1;
				}else{
					cout<<i/m;
				}
			}
			cout<<" ";
			if(i%n==0){
				if((i/n)%2==0){
					cout<<1;
				}else{
					cout<<n;
				}
			}else{
				if((i/n)%2!=0){
					cout<<(i/n)+1;
				}else{
					cout<<n-(i/n);
				}
			}
			break;
		}
	}
	return 0;
}
