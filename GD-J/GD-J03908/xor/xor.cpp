#include <bits/stdc++.h>
using namespace std;
long long n,m,nm,op,sum,sum1,r,i,j,k,a[1000005],b[1000005],s[1000005],mid,ans,c[1000005],d[1000005];
bool l[1000005];
long long cmp(long long nm){
	if(nm==op+1)return op;
	long long max1=-114514114514114514;
	for(long long i=1;i<=op;i++){
		if(l[i])continue;
		bool o=0;
		for(long long j=1;j<nm;j++){
			if(!(s[i]<c[j]&&b[i]<d[j]||s[i]>c[j]&&b[i]>d[j])){
				o=1;
				break;
			}
		}
		if(o)continue;
		if(max1<-1)max1=-1;
		l[i]=1;
		c[nm]=s[i],d[nm]=b[i];
		max1=max(max1,cmp(nm+1));
		c[nm]=0,d[nm]=0;
		l[i]=0;
	}
	if(max1<-1)return nm-1;
	return max1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==m)s[++op]=i,b[op]=i;
		else ans=1;
	}
	if(m==0||m==1){
		for(i=1;i<=n;i++){
			if(a[i]==m)sum++;
		}
		cout<<sum;
		return 0;
	}
	if(ans==0){
		cout<<n;
		return 0;
	}
	for(i=2;i<=n;i++){
		for(k=1;k<=n-i+1;k++){
			r=k+i-1;
			nm=a[k];
			for(j=k+1;j<=r;j++){
				nm=nm|a[j]-nm&a[j];
			}
			if(nm==m)s[++op]=k,b[op]=r;
		}
	}
//	for(i=1;i<=op;i++)cout<<s[i]<<" "<<b[i]<<endl;
//	cout<<endl;
	printf("%lld",cmp(1));
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
