#include<bits/stdc++.h>
using namespace std;
long long n,m,a,cnt=1,pre;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>pre;
		if(pre>a)cnt++;
	}
	long long p=ceil(cnt*1.0/n);
	cout<<p<<" ";
	while(1){
		cnt-=n;
		if(cnt<n){
			if(p%2==1){
				if(cnt==0)cout<<m;
				else cout<<cnt; 
			}
			else{
				cout<<cnt+1;
			}
			break;
		}
	}
	return 0;
}
