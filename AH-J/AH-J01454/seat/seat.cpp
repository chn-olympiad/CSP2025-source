#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,tmp,c=1,r=1;
	bool flag=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			break;
		}
		if(!flag){
			c++;
			if(c>n){
				c=n;
				r++;
				flag=1;
			}
		}else{
			c--;
			if(c<1){
				flag=0;
				c=1;
				r++;
			}
		}	
		
	}
	cout<<r<<" "<<c;
	return 0;
}
