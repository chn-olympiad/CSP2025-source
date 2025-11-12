#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int seat[11][11];
int a[101];
bool cmp(int a,int b){
	return a>b;
} 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];		
	}
	int own=a[1];
	sort(a+1,a+sum+1,cmp);
	
	int pos;
	for(int i=1;i<=sum;i++){
		if(a[i]==own){
			pos=i;	
		}
	}
	int res=(pos%n==0?pos/n:pos/n+1);
	int last=pos%n;
	
	cout<<res<<' ';
	if(res%2==1){
		if(last==0) cout<<n;
		else cout<<last;
	}
	else if(res%2==0){
		if(last==0) cout<<1;
		else cout<<n-last+1;
	}
	cout<<endl;
	
	return 0;
} 
