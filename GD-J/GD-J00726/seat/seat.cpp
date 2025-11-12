#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			s=i+1;
		}
	}
	if(s%n==0){
		if(s/n%2==1){
			cout<<s/n<<" "<<n;
		}
		else{
			cout<<s/n<<" "<<1;
		}
		return 0;
	}
	if((s/n+1)%2==1){
		cout<<s/n+1<<" "<<s%n;
	}
	else{
		cout<<s/n+1<<" "<<n-s%n+1;
	}
	return 0;
} 
