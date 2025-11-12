#include<bits/stdc++.h>
using namespace std;
const int N=200;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	int t=n*m;
	sort(a+1,a+t+1,cmp);
	int f=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			if(i%m==0){
				cout<<i/m<<" ";
				f=i/m;
			}else{
				cout<<i/m+1<<" ";
				f=i/m+1;
			}
			if(i%n==0){
				cout<<n<<" ";
			}else{
				if(f%2==0){
					cout<<i/n+1<<" ";
				}else{
					cout<<i/n-1<<" ";
				}
			}
		}
	}
}
