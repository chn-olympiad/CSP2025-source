#include<bits/stdc++.h> 
using namespace std;
long long m,n,a[102],b[15][15],k,h=1,l=1,c,r;
bool cmp(int a,int b){
	if(a==b){
		return 0;
	}
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+m*n,cmp);
	int er=0;
	for(int i=1;i<=m*n;i++){
		b[h][l]=a[i];
		if(a[i]==k){
			c=l;
			r=h;
		}
		if(l%2==1){
			if(h+1<=n){
				h++;
			}else{
				l++;//记得l++ 
				h=n;
			}
		}else{
			if(h-1>=1){
				h--;
			} else{
				h=1;
				l++; 
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}