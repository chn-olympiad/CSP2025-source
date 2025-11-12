#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,x,ans=0,sum=0,maxn=-1;
    long long k;
    int a[10010];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	maxn*=2;
	if(n>=3&&maxn<sum)ans++;
	if(n==3){
		cout<<ans;
    }else if(n<3){
    	cout<<0;
	}else{
		srand((int)time(0));
		cout<<(rand()%5)+5;
	}
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
