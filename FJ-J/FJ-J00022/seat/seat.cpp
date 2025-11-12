#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int a[101],sum=0,c=1,num=1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(n==1&&m==1){
			cout<<n<<" "<<m;
			return 0;
		}
		sum=a[1];
		if(a[i]>sum)
		num++;
		if(num>n){
			num=n;
			c++;
		}
		if(a[i+1]>sum)
		    num--;
		if(num<1){
			num=1;
			c++;
		}
			if(a[i+1]>sum)
		    num++;
	if(c>m) {
		c=m;
		num=1;
	}
}
		cout<<c<<" "<<num;
		return 0;
}