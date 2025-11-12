#include<bits/stdc++.h>
using namespace std;
long long a[1000][1000],m,n,p[1000],num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>p[i];
	}
	if(m==1&&n==1)cout<<1<<" "<<1;
	for(int i=2;i<=m*n;i++){
		if(p[i]>p[1]){
			num++;
		}
	}
	num=num+1;
	if(m==2&&num>n)cout<<num-n<<" "<<2;
	else if(m==1&&n==1)cout<<1<<" "<<1;
    else if(m==1)cout<<num<<" "<<1;
	else if(n==1)cout<<1<<" "<<num;
	else if(num<=n)cout<<num<<" "<<1;
	else if(n==2&&(num-(num%2))%2==0)cout<<(num-(num%2))/2<<" "<<2;
	else if(n==2&&(num-(num%2))%2==1)cout<<(num-(num%2)+1)/2<<" "<<2;
	return 0;
}