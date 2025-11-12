#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],l[105],r[105],k;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	l[0]=1,r[0]=0;
	for(int i=1;i<=n*m;i++){
		if(l[i-1]%2==0){
			if(r[i-1]!=1)l[i]=l[i-1],r[i]=r[i-1]-1;
			else l[i]=l[i-1]+1,r[i]=r[i-1];
		}
		else{
			if(r[i-1]!=n)l[i]=l[i-1],r[i]=r[i-1]+1;
			else l[i]=l[i-1]+1,r[i]=r[i-1];
		}
		if(k==a[i])k=i;
	}	
	cout<<l[k]<<" "<<r[k];
	return 0;
}
