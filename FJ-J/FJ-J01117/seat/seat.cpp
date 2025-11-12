#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			r=i;
		}
		//cout<<a[i]<<" ";
	}
	//cout<<endl;
	int ans=0;
	if(r%n==0){
		ans=r/n;
		cout<<ans<<" ";
		if(ans%2==1){
			cout<<n<<endl;
		}else cout<<1<<endl;
	} 
	else{
		ans=r/n+1;
		cout<<ans<<" ";
		if(ans%2==1){
			cout<<r%n<<endl; 
		}else cout<<n-r%n+1<<endl;
	}
	//cout<<r; 
	return 0;
}//ÎÒË¯»á¾õ 
