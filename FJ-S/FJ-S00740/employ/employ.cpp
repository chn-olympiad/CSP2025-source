#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,ans,t;
string s;
int a[505];
int b[505];
bool cmp(int x,int y){
	return x<y;
}
int jiecheng(int k){
	if(k==1){
		return 1;
	}
	return k*jiecheng(k-1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	t=jiecheng(n);
	while(t--){
		int w=0,q=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&w<a[b[i]]){
				q++;
				if(q>=m){
					ans++;
					//ans%=998;
					//ans%=244;
					//ans%=353;
					break;
	    		}
			}else{
				w++;
			}
		}
		next_permutation(b+1,b+n+1);
	}
	cout<<ans;
	return 0;
}
/*
for(int i=1;i<=n;i++){
	cout<<b[i]<<" ";
}
cout<<endl;
*/
