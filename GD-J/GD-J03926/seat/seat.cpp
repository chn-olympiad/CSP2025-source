#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int main(){
 	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[n*m];
for(int i=0;i<n*m;i++){
	cin>>a[i];
}
int sum=a[0];
sort(a,a+n*m,cmp);
int x=0,y=0;
for(int i=0;i<n*m;i++){
	if(i%n==0)x++;
	if(a[i]==sum){
 y=i-(x-1)*n+1;
		cout<<x<<" "<<y;
		return 0;
	}
}
	return 0;
}
