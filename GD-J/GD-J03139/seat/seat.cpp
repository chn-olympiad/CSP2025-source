#include<bits/stdc++.h>
using namespace std;
struct node{
	int da;
	int id;
}a[201];
bool cmp(node a,node b){
	return a.da>b.da;
}
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].da;
	}a[1].id=1;
	sort(a+1,a+n*m+1,cmp);
	int j=1,k=1;
	bool f=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<k<<" "<<j;
			return 0;
		}if(f)j++;
		else if(f==0)j--;
		if(j==n+1&&f==1){
			k++;
			j=n;
			f=0;
		}else if(j==0&&f==0){
			k++; 
			j=1; 
			f=1;
		}		
	}	
	return 0;
}
