#include<bits/stdc++.h>
using namespace std;


struct lr{
	long long l,r;
};
long long a[5000+100],n,k,js;
lr b[5000];


inline void sw(long long top)
{
	long long is=a[top];
	long long i=top+1;
	for(;i<n;i++){
		if(is==k){
			b[js].l=top;
			b[js++].r=i-1;
			return;
		}
		else {
			is=is^a[i];
		}
	}
	if(is==k){
		b[js].l=top;
		b[js++].r=i-1;
		return;
	}
	return;
}


bool t(lr a,lr b){
	if(a.r!=b.r)
	return a.r<b.r;
	return a.l>b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++)cin>>a[i];
	for(long long i=0;i<n;i++){
		sw(i);
	}
	lr c[js];
	for(long long i=0;i<js;i++){
		c[i].l=b[i].l;
		c[i].r=b[i].r;
	}
	sort(c,c+js,t);
	/*for(long long i=0;i<js;i++){
		cout<<c[i].l<<' '<<c[i].r<<'\n';
	}*/
	long long top2=-1,sum=0;
		for(long long j=0;j<js;j++){
			if(c[j].l>top2){
				sum++;
				top2=c[j].r;
			}
		}
	cout<<sum;
	return 0;
}
//用深搜太难了