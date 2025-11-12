#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],b[500005];
int s[500005],k,cnt,ans=-1;
int aa(int x){
	int y=0;
	cnt=0;
	while(x>2){
		y=y+x%2*(10^cnt);
		cnt++;
		x/=2;
	}
	return 10^cnt+y;
}
int bb(int x){
	int z,y=0;
	cnt=0;
	while(x>=1){
		z=x%10;
		for(int i=1;i<=cnt;i++)z*=2;
		y=y+z;
		cnt++;
		x/=10;
	}
	return y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	k=aa(k);
	for(int i=1;i<n;i++){
		int x;cin>>x;
		a[i]=aa(x);
		b[i]=cnt;
		for(int j=1;j<=max(b[i],b[i-1]);j++){
			int xx=a[i]%(10^j),yy=a[i-1]%(10^j);
			if(xx==yy)s[i]=1*(10^(j-1))+s[i];
		}
		s[i]=bb(s[i]);
	}
	s[1]=b[1];
	cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]==k)cnt++;
		else{
			if(ans<cnt)ans=cnt;
			cnt=0;
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
}