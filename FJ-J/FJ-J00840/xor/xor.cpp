#include <bits/stdc++.h>
using namespace std;
int sum[500005];
string s,s1;
int ans(int x,int y){
	s="";
	s1="";
	int l1=0,l2=0;
	//cout<<x<<" "<<y<<" ";
	while(x){
		s=char(x%2+'0')+s;
		x/=2;
		l1++;
	}
	while(y){
		s1=char(y%2+'0')+s1;
		y/=2;
		l2++;
	}
	if(l1<l2){
		for(;l1<l2;l1++){
			s='0'+s;
		}
	}
	else {
		for(;l2<l1;l2++){
			s1='0'+s1;
		}
	}
	//cout<<s<<" "<<s1<<endl;
	long long xoo=0;
	int wz=0;
	for(int i=l1-1;i>=0;i--){
		if(s[i]!=s1[i])xoo+=1<<wz;
		//cout<<s[i]<<" "<<s1[i]<<" "<<xoo<<endl;
		wz++;
	}
	return xoo;
}
struct node{
	int x,y;
}a[500005];
int cmp(node x,node y){
	return x.y<y.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum[i]=ans(x,sum[i-1]);
	}
	for(int i=1;i<=n;i++){
		//cout<<sum[i]<<" ";
	}
	int h=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ans(sum[j],sum[i-1])==k){
				h++;
				a[h].x=i;
				a[h].y=j;
			}
		}
	}
	sort(a+1,a+1+h,cmp);
	int t=0;
	int sum=0;
	for(int i=1;i<=h;i++){
		if(t<a[i].x){
			t=a[i].y;
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
