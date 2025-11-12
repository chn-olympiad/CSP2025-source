#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss,a[1000001];
bool cmp(lo x,lo y){
	return x>y;
}
string h;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>h;
	n=h.size();
	for(i=0;i<n;i++){
		if(isdigit(h[i])){
			m++;
			a[m]=int(h[i]-'0');
		}
	}
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;i++)
	printf("%lld",a[i]);
	return 0;
} 
