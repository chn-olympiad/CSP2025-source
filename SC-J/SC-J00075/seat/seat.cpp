#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+m*n+1);
	int pos=0;
	for(int i=1;i<=n*m;++i){
		if(a[i]==tmp){
			pos=i;
			break;
		}
	}
	int n1,m1;
	if(pos%n!=0)n1=pos/n+1;
	else n1=pos/n;
	pos%=n;
	if(n1%2){
		if(pos){
			m1=pos;
		}
		else m1=m;
	}else{
		m1=m-pos+1;
	}
	cout<<n1<<" "<<m1;
	return 0;
} 