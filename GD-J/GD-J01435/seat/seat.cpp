#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int k,l;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[k++]; 
			if(i==0&&j==0){
				l=a[0];
			}
		}
	}
	k=0;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(l==a[k++]){
				int c=k;
				int j=c%n ;
				int h=c/n;
				if(j!=0)h+=1;
				else j=n;
				if(h%2==0){
					cout<<h<<" "<<n-(j-1);
				}
				else{
					cout<<h<<" "<<j;
				}
			} 
		}
	}
	return 0;
} 
