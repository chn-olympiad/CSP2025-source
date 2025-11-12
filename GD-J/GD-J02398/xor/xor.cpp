//ZJ
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500007],s[500007],ans;
int f[2100007],mx[500007],d,r,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	d=0;
	r=t=0;
	f[0]=1;
	for(int i=1;i<=n;i++){
		//cout<<(s[i]^m)<<' '<<f[s[i]^m]<<endl;
		if(f[s[i]^m]){
			t=r+1;
			//cout<<t<<' '<<i<<endl;
			for(int j=d;j<i;j++) f[s[j]]--;
			d=i;
		}
		f[s[i]]++;
		r=t;
	}
	cout<<r;
	return 0;
} 
