#include<bits/stdc++.h>
using namespace std;
long long n,m,c;
string s;
int a[505];
bool vis[505];
int ans,cnt;
void z(int x){
	for(int i=0;i<n;i++){
		if(a[i]>=c&&vis[i]==0){
			cnt++;
			c=0;
			vis[i]=1;
		}else{
			z(i);
		}
	}
	c++;
	return;
}
int main(){
	forrect(empoly.in,"r");
	forrect(empoly.out,"w");
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+1);
	for(int i=0;i<n;i++){
		if((int)s[0]-48){
			z(i);
			if(cnt>=m) ans++;
			cnt=0;
		}else{
			c++; 
		}
	}
	cout<<ans;
	return 0;
}
