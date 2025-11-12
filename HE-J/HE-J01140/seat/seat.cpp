#include<bits/stdc++.h>
using namespace std;
int a[101010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i]; 
	}
	int w=a[1],zu;
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==w){
			zu=i;
			break;
		}
	}
	if(zu%n==0){
		cout<<zu/n<<" ";
		if(zu/n%2==0){
			cout<<1;
		}else{
			cout<<m;
		}
	}else {
		
		int ans=zu/n+1;
		cout<<ans<<" ";
		if(ans%2==0){
			cout<<n-zu%n+1;
		}else
			cout<<zu%n;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
