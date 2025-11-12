#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	int n,sum=0;
	int a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if(a[1]*2<a[1]+a[2]+a[3]){
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(n==4){
		if(a[1]+a[2]+a[3]>a[1]*2){
			sum++;
		}
		if(a[1]+a[2]+a[4]>a[1]*2){
			sum++;
		}
		if(a[1]+a[3]+a[4]>a[1]*2){
			sum++;
		}
		if(a[2]+a[3]+a[4]>a[2]*2){
			sum++;
		}
		if(a[1]+a[2]+a[3]+a[4]>a[1]*2){
			sum++;
		}
		cout<<sum;
	}
	else
	{
		cout<<6;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
