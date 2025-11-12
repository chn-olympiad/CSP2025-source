#include<bits/stdc++.h>
using namespace std;
long long s,n,ans;
int a[5001],m[5001];
void pan(){
	long long max=0,sum=0;
	for(int i=1;i<=5000;i++){
		if(a[i]>max)max=a[i];
		s+=a[i];
	}
	if(max*2<sum)s++;
}
void han(int x,int y){
	if(x==n){
		a[ans++]=m[n];
		pan();
	}
	if(y==1){
		for(int i=x+1;i<=n;i++){
			a[ans++]=m[x];
			han(i+1,n);
		} 
	}
	else{
		for(int i=x+1;i<=n-y+1;i++){
			a[ans++]=m[x];
			han(i+1,y-1);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>m[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<5001;j++){
			a[j]=0;
		}
		han(1,i);
	}
	cout<<s%998%244%353;
	return 0;
} 
