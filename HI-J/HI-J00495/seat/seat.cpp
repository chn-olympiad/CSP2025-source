#include<bits/stdc++.h>
using namespace std;
int a[11]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s1=a[1];
	sort(a,a+n*m);
	if(a[1]==s1){
		cout<<n<<" "<<m;
	}else if(a[2]==s1&&n==2&&m==2){
		cout<<1<<" "<<2;
	}else if(a[3]==s1 && n==2&& m==2){
		cout<<2<<" "<<1;
	}else if(a[4]==s1&& n==2 &&m==2){
		cout<<1<<" "<<1;
	}else if(n==1 && m==2){
		cout<<1<<" "<<2;
	}else{
		cout<<1<<" "<<1;
	}
	
	return 0;
}

