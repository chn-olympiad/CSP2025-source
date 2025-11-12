#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000],b;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+m*n,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			i++;
			if(i%m==0){
				cout<<i/m<<" ";
				if(i/m%2==0)cout<<1;
				else cout<<n;
			}else{
				cout<<i/m+1<<" ";
				if(i/m%2==0)cout<<i%m;
				else cout<<n-i%m+1;
			}
			return 0;
		}
	}
} 
