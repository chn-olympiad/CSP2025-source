#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],maxn;
string a_2[500005];
string to_2(long long x){
	string m;
	if(x==0) m="0";
	while(x!=0){
		m+=char(x%2+'0');
		x/=2;
	}
	
	return m;
}
long long yh(string s1,string s2){
	long long mul=1;
	long long sum=0;
	int len=max(s1.size(),s2.size());
	for(int i=0;i<len;i++){
		if(s1[i]!=s2[i]){
			sum+=mul;
		}
		mul*=2;
	}
	return sum;
}
void fun(long long l,long long cnt){
	if(l>n) return;
	if(cnt<maxn) return;
	long long sum=0;
	for(int r=l;r<=n;r++){
		sum=yh(to_2(sum),a_2[r]);
		if(sum==k){
			if(cnt>maxn) maxn=cnt;
			for(int i=r+1;i<=n;i++){
				fun(i,cnt+1);
			}
		}
	}
	fun(l+1,1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a_2[i]=to_2(a[i]);
	}
	fun(1,1);
	cout<<maxn<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

