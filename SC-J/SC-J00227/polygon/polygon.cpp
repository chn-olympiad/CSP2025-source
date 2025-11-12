#include<bits/stdc++.h>
using namespace std;
const int N=5e7+5;
int n,ans=0;
int a[N],b[N],s[N];
bool l[N]={0};
void sch(){
	int qd,zd,sum=0,max_xb=-1;
	for(int i=1;i<=n;i++){
		if(l[i]==1){
			max_xb=i;
		}
		if(l[i-1]==0&&l[i]==1){
			qd=i;
		}
		if(l[i-1]==1&&l[i]==0){
			zd=i-1;
			sum=sum+(s[zd]-s[qd-1]);
		}
		if(l[i]==1&&i==n){
			zd=i;
			sum=sum+(s[zd]-s[qd-1]);
		}
	}
	if(sum>b[max_xb]){
		ans++;
	}
}
void count_numr(int x){
	if(x<=pow(2,n)-1){
		int ls=x;
		int len_l=0,num_1=0;
		while(ls>0){
			l[++len_l]=ls%2;
			if(l[len_l]==1){
				num_1++;
			}
			ls/=2;
		}
		if(num_1>=3){
			sch();
		}
		x++;
		count_numr(x);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		int max_val=a[1],sum_val=a[1];
		for(int i=2;i<=n;i++){
			max_val=max(max_val,a[i]);
			sum_val+=a[i];
		}
		if(sum_val>max_val*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		s[0]=0;s[1]=a[1];
		for(int i=2;i<=n;i++){
			s[i]=s[i-1]+a[i];
		}
		for(int i=1;i<=n;i++){
			b[i]=a[i]*2;
		}
		count_numr(1);
		cout<<ans;
	}
	return 0;
}