#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[102];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int temp=a[0];
	sort(a,a+(n*m));
	int noa[102];
	for(int i=0;i<n*m;i++){
		noa[i]=a[n*m-i-1];
	}
	for(int i=0;i<n*m;i++){
		if(noa[i]==temp){
			temp=i;
		}
	}
	int p=1,q=1;
	while(1){
	for(int i=1;i<n;i++){q++;temp--;if(temp==0){cout<<p<<" "<<q;return 0;}}
	p++;temp--;if(temp==0){cout<<p<<" "<<q;return 0;}
	for(int i=1;i<n;i++){q--;temp--;if(temp==0){cout<<p<<" "<<q;return 0;}}
	p++;temp--;if(temp==0){cout<<p<<" "<<q;return 0;}
	}
	return 0;
}
