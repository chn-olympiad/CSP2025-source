#include<bits/stdc++.h>
using namespace std;
long long i,j,n,k,a[500005],w,ans;
long long l,r;
struct op{
	long long left,right;
}x[500005];
string its(long long x){
	string q="";
	int v=0;
	while(x!=0){
		v=x%2;
		q+=char(v+'0');
		x/=2;
	}
	return q;
}
long long sti(string l){
	long long y=0;
	for(int k=0;k<l.size();k++){
		y=y*2+l[k]-'0';
	}
	return y;
}
string exor(long long x,long long y){
	if(x<y)swap(x,y);
	string q=its(x),p=its(y),o="",v="";
	for(int k=0;k<q.size();k++){
		if(k<p.size()){
			if(q[k]==p[k])o+='0';
			else o+='1';
		}
		else o+=q[k];
	}
	for(int k=0;k<o.size();k++)v+=o[o.size()-k-1];
	return v;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)a[i]=(a[i]^a[i-1]);
	long long start=0;
	for(i=start;i<n;i=start){
		for(j=i+1;j<=n;j++){
			if(sti(exor(a[i],a[j]))==k){
				ans++,start=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
