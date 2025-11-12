#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int arr[6000];
void num(int c,int x){
	if(x==0)return ;
	if(c>=arr[x]){
		num(c,x-1);
		c-=arr[x];
		num(c,x-1);
	}
	else {
		ans++;
		int tmp=x-1;
		for(int i=1;i<=tmp;i++){
			long long a=1,b=1;
			for(int j=1;j<=i;j++){
				a*=j;
				b*=tmp-j+1;
			}
			ans+=b/a;
		}
		num(c,x-1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=n;i>=3;i--){
		num(arr[i],i-1);
	}
	cout<<ans;
	return 0;
} 
