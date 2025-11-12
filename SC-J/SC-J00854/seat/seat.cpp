#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int flag=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==flag){
			flag=i;
			break;
		}
	}
	//cout<<flag<<" ";
	int num1=flag/n,num2=flag%n;
	if(num2==0){
		cout<<num1<<" ";
		if(num1%2==0){
			cout<<1;
		}
		else{
			cout<<n;
		}
	}
	else{
		num1+=1;
		cout<<num1<<" ";
		if(num1%2==0){
			cout<<n-num2+1;
		}
		else{
			cout<<num2;
		}
	}
	return 0;
}