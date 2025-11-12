#include<bits/stdc++.h>
using namespace std;
const int x=1e5+5;
int t,n,ans,sum1,sum2,num,num1a,num1b,num2a,num2b,num3;
struct ren{
	int b,c,d;
}a[x];
bool cmp1(ren x,ren y){
	if(x.b!=y.b) return x.b>y.b;
}
bool cmp2(ren x,ren y){
	if(x.c!=y.c) return x.c>y.c;
}
bool cmp3(ren x,ren y){
	if(x.d!=y.d) return x.d>y.d;
}
int f(int x){
	if(x==n){
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++)
			ans+=a[i].b;
		return ans;
	}
}
int fx(int x){
	if(x==n){
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(i<=n/2) num1a+=a[i].b;
			else num1b+=a[i].b;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(i<=n/2) num2a+=a[i].c;
			else num2b+=a[i].c;
		}
		if(num1a>=num2a){
			num+=num1a+num2b;
			return num;
		}else {
			num+=num2a+num1b;
			return num;
		}		
	}
	}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].b>>a[i].c>>a[i].d;
			
			if(a[i].c==0&&a[i].d==0)
				sum1++;
			if(a[i].d==0)
				sum2++;
		}
		if(sum1==n) cout<<f(sum1)<<endl;
		cout<<fx(sum2)<<endl;	
	}
	return 0;
}
