#include<bits/stdc++.h>
using namespace std;
	int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

int n,m,k;
cin>>n>>m;
int h=n*m;
for(int i=1;i<=h;i++){
	cin>>a[i];
}
k=a[1];
int w=0;
sort(a+1,a+1+h);
for(int i=h;i>=1;i--){
	if(a[i]==k){
		w=h-i+1;
		break;
	} 
}

if(m==1){
	cout<<w<<" "<<1;
	return 0; 
}
if(w<=n||n==1){
	cout<<1<<" "<<w;
	return 0;
}else{
	int p=w/n;
	if(w%n!=0){
		p+=1;
	}
	cout<<p<<" ";
	if(p%2==1){
		cout<<w-n*(m-1);
	}else{
		cout<<w%n+1;
	}
}
	return 0;
}
