#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int sum=0;
int a[5500];
bool cmp(int x,int y){
	return x<y;
}
int solve_1(int n){
	if(sum>2*a[n]) return 1;
		else return 0;
}
int solve_2(int n){
	int ans=0;
	if(sum-a[n]>2*a[n-1]){
			ans++;
	}
		for(int i=1;i<n;i++){
			if(sum-a[i]>2*a[n]){
				ans++;
			//	cout<<i<<endl;
			}
		}
		if(sum>2*a[n]){
			ans++;	
		}
		return ans;
}
int solve_3(int x,int n){
	int c=n;
	int b=x;
	int cn1=1,cn2=1;
	while(b){
		cn1=cn1*c;
		c--;
		b--;
	}
	while(x){
		cn2=cn2*x;
		x--;
	}
	return cn1/cn2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1,cmp);

	if(n==3){
		cout<<solve_1(n);
	}
	if(n==4){
		cout<<solve_2(n);
	}
	if(a[n]==1){
		int cnt=0;
		for(int i=3;i<=n;i++){
			cnt+=solve_3(i,n);
		}
		cout<<cnt;
	}
	return 0;
}
