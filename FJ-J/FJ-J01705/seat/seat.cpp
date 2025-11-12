#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >>n>>m;
	long long a[n*m],a1;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	a1=a[1];	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			a1=i;
		}
	}//µÚ¼¸Ãû
	int x=0,y=0,flag=0;
	for(int i=1;i<=a1;i++){
		if(flag==0){
			y++;
			if(y>m){
				y=m;
				flag=1;
			}
		}else{
			y--;
			if(y<1){
				y=1;
				flag=0;
			}
		}
		if((i-1)%m==0){
			x++;
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 
