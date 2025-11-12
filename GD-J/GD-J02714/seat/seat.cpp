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
	int a[101],z=n*m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int p=a[0];
	sort(a+0,a+z,cmp);
	int q;
	for(int i=0;i<z;i++){
		if(a[i]==p){
			q=i;
			break;
		}
	}
	int x=q/n+1,y;
	if(x%2==0){
		y=n-((q+1)%n)+1;
	}else{
		y=q%n+1;
	}
	cout<<x<<" "<<y<<endl;
	
	return 0;
} 
