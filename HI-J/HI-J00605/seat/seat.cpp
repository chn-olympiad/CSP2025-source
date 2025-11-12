#include<bits/stdc++.h>
using namespace std;
int a[1500];
int c[1500]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l=0;
	cin>>n>>m;
	l=n*m;
	int num=0;
	for(int i=1;i<=l;i++){
		cin>>a[i];
		if(i==1){
			num=a[i];
		}
	}
	int x=1,y=1,q=0;
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--){
		if(a[i]==num){
			cout<<y<<" "<<x;
		}
		else{
			if(x==n&&y%2!=0&&y<m){
				y++;
				q=1;
			}
			else if(x==1&&y%2==0&&y<m){
				y++;
				q=1;
			}
			if(y%2!=0&&x<n&&q==0){
				x++;
			}
			else if(y%2!=0){
				q=0;
			}
			else if(y%2==0&&x>1&&q==0){
				x--;
			}
			else if(y%2==0){
				q=0;
			}
		}	
	}
	return 0;
}
