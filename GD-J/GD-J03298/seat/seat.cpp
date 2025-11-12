#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m;
int a[N],num=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])num++;
	}
	int line=num/n+(num%n==0?0:1);
	if(line%2==1){
		if(num%n==0)num=n;
		else num=num%n;
		cout<<line<<' '<<num;
	}else{
		if(num%n==0)num=n;
		else num=num%n;
		cout<<line<<' '<<n-num+1;
	}
	return 0;
}

