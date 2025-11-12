#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m;
int a[10005];
bool cmp(int a,int b){
	return a>b;
}
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cin>>a[1];
	
	int k=a[1];
	
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			if(i%m==0){
				int n1=i/m;
				if(n1%2==0){
					int m1=m-i%m+1;
					cout<<n1<<" "<<m1;
					return 0;
				}
				else if(n1%2!=0){
					int m1=i%m;
					cout<<n1<<" "<<m1;
					return 0;
				}
			}
			else if(i%m!=0){
				int n1=(i-i%m)/m+1;
				if(n1%2==0){
					int m1=m-i%m+1;
					cout<<n1<<" "<<m1;
					return 0;
				}
				else if(n1%2!=0){
					int m1=i%m;
					cout<<n1<<" "<<m1;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*int o=i/m;
			if(o%2==0){
				o=
				int n1=i/m;//n坐标 
				if(n1%2==0){//判断奇偶数列再算m 
					int m1=m-i%m+1;
					cout<<m1<<" "<<n1;
					return 0;
				}
				else if(n1%2!=0){//奇数 
					int m1=i%m;
					cout<<m1<<" "<<n1;
					return 0;
				}
			}
			else if(o!=0){
				int n1=i/m+1;//n坐标 
				if(n1%2==0){
					int m1=m-i%m+1;
					cout<<m1<<" "<<n1;
					return 0;
				}
				else if(n1%2!=0){
					int m1=i%m;
					cout<<m1<<" "<<n1;
					return 0;
				}
			}
*/
