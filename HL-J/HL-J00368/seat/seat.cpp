#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];//小r的成绩 
	
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		b[i]=a[n*m-i+1];
		
	}
	
	for(int i=1;i<=n*m;i++){
		if(b[i]==x){
			y=i;
			break;
		}
	}
	
	if(y==1){
		cout<<"1 1";
	}
	else if(y==n*m){
		cout<<m<<" "<<n;
	}
	else
	{
		int s,t;
		
		//正好是n的倍数 
		if(y%n==0){
			s=y/n;
			if(s%2!=0){
				t=n;
				cout<<s<<" "<<t;
			}
			else
			{
				cout<<s<<" "<<1;
			}
		}
		
		else
		{
			s=y/n+1;
			if(s%2==0){
				t=n-y%n+1;
			}
			else
			{
				t=n-y%n-1;
			}
			cout<<s<<" "<<t;
		}
		
	}
	return 0;
}
	














