#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt;
int a[5005];
int oc[5005],x[5005];
void f(int d,int p){
	if(d>p){
		int sum=0,maxx=-1;
		for(int i=1;i<=d;i++){
			if(oc[i]){
				if(a[i]>maxx)maxx=a[i];
				sum+=a[i];
			}
		}
		if(sum>2*maxx)cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!oc[i] and a[i]>x[d-1]){
			oc[i]=1;
			x[d]=a[i];
			f(d+1,p);
			oc[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)cout<<0;
	else{
		int x,y,z;
		cin>>x>>y>>z;
		if(x+y+z>2*max(x,max(y,z)))cout<<1;
	}
	return 0;
}
