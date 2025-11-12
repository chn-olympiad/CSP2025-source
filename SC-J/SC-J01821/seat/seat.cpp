#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++){
    	cin>>a[i];
	}
	int d=a[1];
	sort(a,a+s+1);
	int x=1;
	for(int i=s;i>=1;i--){
		if(a[i]==d){
			break;
		}
		x++;
	}
	int num;
	if(x%n==0){
		num=x/n;
		cout<<num<<" ";
	}
	else{
		num=x/n+1;
		cout<<num<<" ";
	}
	if(num%2==0){
		if(x%n==0){
			cout<<1;
		}
		else{
			cout<<m-x%n+1;
		}
	}
	else{
		if(x%n==0){
			cout<<m;
		}
		else{
			cout<<x%n;
		}
	}
		
    return 0;
}