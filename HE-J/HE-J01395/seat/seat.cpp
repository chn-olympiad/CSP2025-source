#include<bits/stdc++.h>
using namespace std;
long long n,m,num[105],r,x=1,y=1,sum=1;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(num,-1,sizeof(num));
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
	}
	r=num[1];
	sort(num+1,num+n*m+1,cmp);
	if (n==1){
		for(int i=1;i<=n;i++){
			if (num[i]==r){
				cout<<i<<" "<<1;
				return 0;
			} 
		}
	}
	while(true){
		if (num[sum]==r){
			break;
		}
		if (x%2==1){
			y+=1;
			sum+=1;
		}else{
			y-=1;
			sum+=1;
		}
		if (num[sum]==r){
			break;
		}
		if (y==1 || y==n){
			x+=1;
			sum+=1;
		}
		if (num[sum]==r){
			break;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
