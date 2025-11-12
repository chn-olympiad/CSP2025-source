#include<bits/stdc++.h>
using namespace std;
int a[10050];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int o_o=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(o_o==a[i]){
			o_o=n*m-i+1;
			break;
		}
	}
	int roow=ceil(1.0*o_o/m);
	if(roow%2==1){//奇数列从上往下 
		cout<<roow<<" ";
		if(o_o%m==0)cout<<m;
		else cout<<o_o%m;
	}else{//偶数列从下往上
	 	cout<<roow<<" "; 
		if(o_o%m==0)cout<<1;
		else cout<<m-(o_o%m)+1;		
	}
	return 0;
} 
