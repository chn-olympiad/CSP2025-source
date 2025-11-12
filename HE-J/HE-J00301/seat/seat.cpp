#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+50;
struct student{
	long long zuoweihao,chengji;
}a[N];
long long n,m,c=0,r=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i].chengji;
		a[i].zuoweihao=i;
	}
	long long flag=0;
	for(long long i=1;i<=n*m;i++){
		if(flag==1) break;
		flag=1;
		for(long long j=1;j<=n*m;j++){
			if(a[j].chengji<a[j+1].chengji){
				swap(a[j],a[j+1]);
				flag=0;
			}
		}
	}
	long long shangxia=1;
	for(long long i=1;i<=n*m;i++){
		if(shangxia==1){
			c++;
			if(c>m){
				c--;r++;shangxia=2;
			}
		}
		else if(shangxia==2){
			c--;
			if(c<1){
				c++;r++;shangxia=1;
			}
		}
		if(a[i].zuoweihao==1){
			cout<<r<<' '<<c;
			return 0;
		}
	}
	return 0;
}
