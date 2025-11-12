#include<bits/stdc++.h>
using namespace std;
int n,m,q,s;
int a[200];
int k;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n行m列 
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	q=a[1];
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++){
		if(a[i]==q){
			q=i;
			break;
		}
	}
//	cout<<s<<" "<<q;
	while(q>=n){
		k++;
		q-=n;
	}
//	cout<<k<<" "<<q<<endl;
	//k代表小R在第k列
	if(k==0){
		cout<<1<<" "<<q;
		return 0;
	}
	if(q==0){//此时小R在第k列 
		if(k%2==0){
			cout<<k<<" "<<1;
		}else{
			cout<<k<<" "<<n;
		}
	}else{//此时小R在第k+1列
		int k2=k+1;
		if(k2%2==0){
			cout<<k2<<" "<<n-q+1; 
		}else{
			cout<<k2<<" "<<q; 
		}
	}
	return 0;
}
/*
99 100 97 98
1   2   3  4
100 99 98 97
 1   2  3  4
2 2
  1  2 
1 1  4  
2 2  3  
 
*/
