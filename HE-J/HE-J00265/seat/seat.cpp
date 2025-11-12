#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[20][20],c,d,e=1;
vector<int> a(1,100);
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	for(int i=0;i<c;i++){
		cin>>a[i];
		d=a[0];
	}
	
	sort(a.begin(),a.begin()+c);
	for(int i=0;i<c;i++){
		
		if(a[i]==d){
			d=i;
		}
	}
	d=c-d;
	for(int i=1;i<=m;i++){
		if(i%m==0){
			for(int j=1;j<=n;j++){
				if(e==d){
					cout<<i<<" "<<j;
				}
				e++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(e==d){
					cout<<i<<" "<<j;
				}
				e++;
			}
		}
	}
	return 0;
} 

