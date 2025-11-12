#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001]; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	int mc;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			mc=i;
			break;	
		}
	}
	int h,l;
	l=mc/n;
	h=mc%n;
	if(l%2!=0){
		if(h==0){
			cout<<l<<" "<<n;
		}else{
			cout<<l+1<<" "<<n-h+1;
		}
	}else{
		if(h==0){
			cout<<l<<" "<<1;
		}else{
			cout<<l+1<<" "<<h;
		}
	}
	
	return 0;
} /*
3 3
94 95 96 97 98 99 100 93 92
100 95	94
99 	96	93
98	97	92
*/
//9:22 模拟 结 
