#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005]={0},ans=0;
int xor1(int a,int b){
	char m[25];
	int t=0,s=0;
	while(a!=0&&b!=0){
		if(a%2==b%2)m[t]=0;
		else m[t]=1;
		a/=2;
		b/=2;
		t++;
	}for(int i=0;i<t;i++){
		s+=pow(2,i)*m[i];
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			f[i]==1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int b[500005];
			for(int l=1;l<=n;l++){
				b[l]=a[l];
			}
			for(int l=i;l<j;l++){
				if(f[l]==1||f[l+1]==1){
					break;
				}
				int s1=xor1(a[l],a[l+1]);
				if(s1==k){
					ans++;
					for(int m=i;m<=l;m++){
						f[m]==1;
					}
					break;
				}else{
					a[l+1]=s1;
				}
			}
			for(int l=1;l<=n;l++){
				a[l]=b[l];
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
