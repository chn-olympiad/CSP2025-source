#include<bits/stdc++.h> 
using namespace std;
const int maxn=1e6+5;
long long n,m,a[maxn],k,num,ans1,ans2;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	k=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==k){
			num=i+1;
		}
		else{
			continue;
		}
	}
	if(num%n==0){
		if(num/n%2==0){
			ans2=1;
		}
		else{
			ans2=n;
		}
		ans1=num/n;
	}
	else if(num/n%2==0){
		ans2=num%n;
		ans1=num/n+1;
	}
	else{
		ans2=n-num%n+1;
		ans1=num/n+1;
	}
	cout<<num<<" "<<ans1<<" "<<ans2;
	return 0;
}