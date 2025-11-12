#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[110],b[15][15];
bool f=0;
bool cmp(int x,int y){
	if(x<y){
		return x>y;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int num=a[0];
	sort(a,a+n*m,cmp);
	int sum;
	for(int i=0;i<n*m;i++){
		if(a[i]==num){
			sum=i+1;
			break;
		}
	}
	int d;
	if(sum%n==0){
		d=sum/n;
	}else{
		d=sum/n+1;
	}
	if(d%2==1){
		cout<<d<<" ";
		if(sum%n==0){
			cout<<n;
		}else{
			cout<<sum%n;
		}
	}else{
		cout<<d<<" ";
		if(sum%n==0){
			cout<<1;
		}else{
			cout<<n-sum%n+1;
		}
	} 
	return 0;
} 
