#include <iostream>
#include <algorithm>
using namespace std;
int a[50005];
int n,cnt=0,maxn;
bool cmp(int x,int y){
	return x>y;
}
int dg(int num,int i){
	int sum=a[i];
	if(num==1)
	return sum;
	for(int j=i+1;j<=n;j++){
		int next=dg(num-1,j);
		if(next+sum>maxn){
			cnt++;
		}
		
	return	sum+next;
}
	
	
	
	
}
int main()
{//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);

	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n-i+1;j++)
		{maxn=a[j]*2;
		dg(i,j);
		}
	}
	
	
	return 0;
}
