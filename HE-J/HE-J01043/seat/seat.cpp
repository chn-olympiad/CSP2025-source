#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int b[1010][1010];
int xiaor;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int psum=n*m;
	for(int i=1;i<=psum;i++){
		cin>>a[i];
	}
	xiaor=a[1];	
	sort(a+1,a+n+1,cmp);
	int i=1,j=1;
	for(int x=1;x<=psum;x++){
		if(a[x]==xiaor){
			cout<<j<<" "<<i;
			break;
		}
		if((i==1 && j!=1) || (i==n)){
			j++;
		} 
		else{
			if(j%2==1){
				i++;
			}
			else{
				i--; 
			}
		}
	}
	
	
	return 0;
} 
