#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[1000010],R;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		R=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
	int l=1; 
	for(int i=1;i<=n;i++) {
		if(i%2==0){
			for(int j=m;j>=1;j--,++l){
				if(a[l]==R){
					cout<<i<<" "<<j;	
					return 0;
				} 
			}
		}else{
			for(int j=1;j<=m;j++,l++){
				if(a[l]==R){
					cout<<i<<" "<<j;	
					return 0;
				} 
			}
		}
	}	
	return 0;
} 
