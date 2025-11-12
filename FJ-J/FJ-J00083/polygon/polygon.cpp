#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 5005;
int a[maxn];
int cc;
int b[maxn];
int ans =0;
int cnt = 0;
int maxw = -1;
int f(int x,int y){
	if(x == cc){
		maxw = -1;
	}
	if(x==0){
		int ss = 0;
		for(int i = 1;i<=cc;i++){
			ss+=b[i];
		}
		if(2*maxw < ss){
			cnt++;
			for(int i = 1;i<=cc;i++){
				cout<<b[i]<<" ";
			}
			cout<<endl;
		}
		return cnt;
	}
	for(int i = y;i<=n-cc+1;i++){
		b[i] = a[i];
		maxw = max(maxw,b[i]);
		ans+= f(x-1,i);
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n == 3){
		int a,b,c;
		cin>>a>>b>>c;
		int x = max(a,max(b,c));
		if(2*x < a+b+c){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 3;i<=n;i++){//i±ßÊý 
		cc = i;
		f(i,1);
	}
	cout<<cnt % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

