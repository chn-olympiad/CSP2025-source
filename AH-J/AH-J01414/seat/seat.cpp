#include<bits/stdc++.h>
using namespace std;
long long n,m,x=1,y=1,s,num,a[105];
bool fl=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++)cin>>a[i];
	num=a[1];
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++){
		if(a[i]==num){
			num=i;
			break;
		}
	}
	for(int i=2;i<=num;i++){
		if(y==n&&fl!=1){
			x++;
			fl=1;
		}	
		else if(y==1&&x!=1&&fl!=1){
			x++;
			fl=1;
		}
		else if(x%2==1){
			fl=0;
			y++;
		}
		else {
			fl=0;
			y--;
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 
