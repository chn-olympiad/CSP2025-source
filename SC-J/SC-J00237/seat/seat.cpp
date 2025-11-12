#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[105];
int b[12][12];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1],h,y;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			h=i;
			break;	
		}
	}
	int z=h/n;
	if(h%n!=0){
		w=z+1;	
	}
	else{
		w=z;	
	}
	if(w%2==0)y=n-(h%n)+1;
	else y=h%n;
	if(y==0)y=n;
	cout<<w<<" "<<y;
	return 0;
} 