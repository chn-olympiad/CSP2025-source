#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans1=1,ans2=1;
int a[110]; 
bool cmp(int t,int s){
	return t>s;
}
bool flag=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]!=k){
			if(ans1<=n&&flag==0) ans1++;
			if(ans1<=n&&flag==1) ans1--;
			if(ans1>n) ans2++,ans1=n,flag=1;
			if(ans1<1) ans2++,ans1=1,flag=0; 
		}else{
			cout<<ans2<<' '<<ans1;
			return 0;
		}
	}
	return 0;
} 
