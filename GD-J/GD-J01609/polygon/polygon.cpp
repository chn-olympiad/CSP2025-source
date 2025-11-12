#include<bits/stdc++.h>
using namespace std;
using namespace std;
int r[5010],n,ans=0;
int solve(int x,int y,int z=0,int la=0){
	int a;
	for(int i=x;i<n-y+1;i++){
		a=r[i];
		cout << a << endl;
		int l=max(a,z),l1=a+la;
		if(y==1){
			if(la>l*2){
				ans++;
			}
			continue;
		}
		solve(x+1,y-1,l,l1);
	}
	return 0;
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >>r[i]; 
	}
	if(n<3){
		cout << 0;
		return 0;
	}
	int num=3;
	while(num<n){
		solve(0,num);
		num++;
	}
	int e=0,ee=-1;
	for(int i=0;i<n;i++){
		e+=r[i];
		ee=max(ee,r[i]);
	}
	if(e>ee*2)ans++;
	ans%=998244353;
	cout << ans;
	return 0;
}
