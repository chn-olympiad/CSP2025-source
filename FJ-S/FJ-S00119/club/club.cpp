#include<bits/stdc++.h>
using namespace std;
int T,n,sum;
struct XX{
	int h,dx;
}b1[100005],b2[100005],b3[100005];
struct SS{
	int m1,m2,m3,maxn1,maxn2,maxn3;
}a[100005];
bool cmp(SS x,SS y){
	if(x.maxn1!=y.maxn1)return x.maxn1>y.maxn1;
	if(x.maxn2!=y.maxn2)return x.maxn2>y.maxn2;
	return x.maxn3>y.maxn3;
}
bool cmp1(XX x,XX y){
	return x.dx<y.dx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		sum=0;
		int h1=0,h2=0,h3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
			a[i].maxn1=max(a[i].m1,max(a[i].m2,a[i].m3));
			a[i].maxn3=min(min(a[i].m1,a[i].m2),a[i].m3);
			a[i].maxn2=a[i].m1+a[i].m2+a[i].m3-a[i].maxn1-a[i].maxn3;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			sum+=a[i].maxn1;
			if(a[i].maxn1==a[i].m1){
				h1++;
				b1[h1].dx=a[i].maxn1-a[i].maxn2;
				b1[h1].h=i;
			}else if(a[i].maxn1==a[i].m2){
				h2++;
				b2[h2].dx=a[i].maxn1-a[i].maxn2;
				b2[h2].h=i;
			}else {
				h3++;
				b3[h3].dx=a[i].maxn1-a[i].maxn2;
				b3[h3].h=i;
			}
		}
		if(h1>n/2){
			sort(b1+1,b1+1+h1,cmp1);
			for(int i=1;i<=h1-n/2;i++){
				sum-=b1[i].dx;
			}
			cout<<sum<<endl;
		}else if(h2>n/2){
			sort(b2+1,b2+1+h2,cmp1);
			for(int i=1;i<=h2-n/2;i++){
				sum-=b2[i].dx;
			}
			cout<<sum<<endl;
		}else if(h3>n/2){
			sort(b3+1,b3+1+h3,cmp1);
			for(int i=1;i<=h3-n/2;i++){
				sum-=b3[i].dx;
			}
			cout<<sum<<endl;
		}else{
			cout<<sum<<endl;
		}
		
	}
	return 0;
}
/*
bool operator
priority_queue
*/
