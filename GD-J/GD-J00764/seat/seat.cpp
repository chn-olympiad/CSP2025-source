#include<bits/stdc++.h>
using namespace std;
int x[10000007];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
	}
	int num=x[1];
	sort(x+1,x+n*m+1,cmp);
	int cnt;
	for(int i=1;i<=n*m;i++){
		if(x[i]==num) cnt=i;
	}
	if(cnt%n==0){
		int arr=cnt/n;
		int sum;
		if(arr%2==0){
			sum=1;
		}
		else sum=n;
		cout<<arr<<" "<<sum; 
	}
	else {
		int arr=cnt/n+1;
		int sum;
		if(arr%2==0){
			sum=arr*n-cnt+1;
		}
		else {
			sum=cnt-(arr-1)*n;
		}
		cout<<arr<<" "<<sum; 
	}
}
 
