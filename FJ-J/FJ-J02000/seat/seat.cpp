#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","a",stdout);
	int m,n;
	cin>>m>>n;
	int a[m*n],R,T=0,W=m*n;
	cin>>R;
	a[0]=R;
	for(int i=1;i<m*n;i++){
		cin>>a[i];
	} 
	sort(a,a+m*n);
	int mid=(T+W)/2;
	while(1){
		mid=(T+W)/2;
		if(a[mid]==R){
			break;
		}else if(a[mid]>R){
			W=mid;
		}else{
			T=mid;
		}
	}
	mid=m*n-mid; 
	int h=0,l;
	if(mid%n){
		l=mid/n+1;
		h=mid%n;
	}else{
		l=mid/n;
		h=n;
	}
	if(l%2==0){
		h=n-h+1;
	}
	cout<<l<<" "<<h;

	return 0;
} 
//가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가
//가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가가꼇삔畇！！！！！
//！！！！！！！！ ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ 
