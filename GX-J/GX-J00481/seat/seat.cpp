#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	int b=n*m;
	int a[b];
	cin>>a[b];
	c=a[0];
	for(int i=0;i<b;i++){
		for(int j=i+1;j<b;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<b;i++){
		if(a[i]==c){
			c=i;
		}
	}
	int e=c-c%n;
	if(c%n!=0&&(e/n+1)%2!=0){
		cout<<c%n<<e/n+1;
	}
	else if(c%n!=0&&(e/n+1)%2==0){
		cout<<4-e<<c/n;
	}
	else if(c%n==0&&c/n%2!=0){
		cout<<4<<c/n;
	}
	else if(c%n==0&&c/n%2==0){
		cout<<1<<c/n;
	}
	return 0;
}
