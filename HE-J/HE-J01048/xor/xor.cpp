#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int n,k;int a[N],sum1[N];
int ans;
struct re{
	int num;
	int cnt;
}sum2[N];
bool cmp(re x,re y){
	if(x.cnt ==y.cnt ) return x.num <y.num ;
	else return x.cnt <y.cnt ;
}
int d(int x,int num){
	int l=-1,r=n+1;
	while(l+1!=r){
		int mid=l+r>>1;
		if(sum2[mid].cnt >=x) r=mid;
		else l=mid;
	}
	int ll=r;
//	cout<<l<<endl;
	if(sum2[r].cnt !=x){
////		cout<<"1111111"<<endl;
	 return 1e9;
	}
	l=-1,r=n+1;
	while(l+1!=r){
		int mid=l+r>>1;
		if(sum2[mid].cnt >x) r=mid;
		else l=mid;
	}
//	cout<<r<<endl;
	int rr=l;
//	l=ll,r=rr;
//	while(l+1!=r){
//		int mid=l+r>>1;
//		if(sum2[mid].num >num) r=mid;
//		else l=mid;
//	}
	for(int i=ll;i<=rr;i++){
		if(sum2[i].num >=num) return sum2[i].num ;
	}
//	cout<<l<<' '<<r<<' '<<sum2[r].cnt <<sum2[l].cnt <<endl;
 return 1e9;
//	cout<<l<<' '<<r<<' '<<sum2[r].num<<endl;
//	return sum2[r].num ;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum1[i] =a[i]^sum1[i-1] ;
		sum2[i].cnt =sum1[i];
		sum2[i].num =i;
	}
	sort(sum2+1,sum2+n+1,cmp);
//	for(int i=1;i<=n;i++) cout<<sum2[i].cnt <<' ';
//	cout<<endl;
	int st=1,mi=1e9;
	for(int i=1;i<=n+1;i++){
		if(i>mi){
//			cout<<i<<' '<<mi<<endl;
			mi=1e9;
//			cout<<i<<' '<<ans<<' '<<1111111<<endl;
			ans++;
		}
		if(mi==n+1) break;
		mi=min(mi,d(sum1[i-1]^k,i));
		int gg=sum1[i-1]^k;
//		cout<<i<<' '<<gg<<' '<<d(sum1[i-1]^k,i)<<' '<<mi<<endl;

	}
	cout<<ans;
	return 0;
}
