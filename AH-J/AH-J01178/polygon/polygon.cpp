#include<bits/stdc++.h>
using namespace std;
int first=1;
int qian[50005];
int last;
int a[10000];
void work1(){
	if(a[3]+a[1]+a[2]>a[3]*2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
void work2(int n){
	int cnt=0;
	int chang;
	while(first+2<=n){
		
		last=first+2;
		chang=qian[last]-qian[first-1];
		while(last<=n)
		{
	    if(a[last]*2<(qian[last]-qian[first-1]))
	    {
			cnt++;
		}
		if(chang+a[last]>2*a[last]){
		cnt++;
	}
		last++;
	}
	first++;
}
cout<<cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	qian[0]=0;
	qian[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		qian[i]=a[i]+qian[i-1];
	}
	if(n==3)
	{
		work1();
	}
	else
	{
		work2(n);
	}
	return 0;
	}
