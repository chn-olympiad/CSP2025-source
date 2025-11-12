#include<bits/stdc++.h>
using namespace std;
int read();
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	if(n<3) cout<<0<<endl;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==3){
		sort(a,a+n);
		//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
		if((a[0]+a[1])>a[2]) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
int read(){
	char c;
	int f=1,r=0;
	while(!isdigit(c=getchar())){
		if(c=='-') f=-1;
	}
	r=c^48;
	while(isdigit(c=getchar())){
		r=(r*10);
		r+=c^48;
	}
	return r*f;
}
