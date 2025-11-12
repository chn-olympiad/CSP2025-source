#include<bits/stdc++.h>
using namespace std;
bool smp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,o[111],r,a;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		if(i==0){
			
			cin>>r;
			o[0]=r;
		}else{
			cin>>o[i];
		}
		
	}
	sort(o,o+m*n,smp);
	for(int i=0;i<n*m;i++){
		if(o[i]==r){
			a=i;
			break;
		}
	}
	int n1,m1;
	m1=a/n+1;
	if(m1%2 == 1){
		n1=a%n+1;
	}else{
		n1=n-a%n;
	}
	cout<<m1<<' '<<n1;
	return 0;
}
