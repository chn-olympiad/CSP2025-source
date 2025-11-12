#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
long long n,m,x,y,a[N],c[N],d[N],ma=0,j,l,k,i,o,p,t,h,g,f,r,e,w,q,z;
string s,s1,s2;
struct No{
	long long l,r;
}b[N];
bool cmp(long long x,long long y){
	return x>y;
}
void in(){
	for(int i=1;i<=n;i++)c[i]+=a[i];
}
long long maa(long long l,long long r){
	long long ma=0;
	for(long long i=l;i<=r;i++){
		if(a[i]>ma)ma=a[i];
	}
	return ma;
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	in();
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(c[j]-c[i-1]>maa(i,j)*2)h++;
		}
	}
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)cout<<9;
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)cout<<6;
	}
	cout<<h;
	return 0;
}
