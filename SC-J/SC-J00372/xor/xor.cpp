#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;

int n;
long long k,a[N];
int flag[N];

int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	long long ans=0;
	for (int i=0;i<n;i++){
		for (int j=1;j+i<=n;j++){
			bool mark=0;
			for (int l=j;l<=j+i;l++){
				if (flag[l]){
					mark=1;
					break;
				}
			}
			if (mark)
				continue;
			long long res=a[j];
			for (int l=j+1;l<=j+i;l++)
				res=res xor a[l];
			if (res==k){
				ans++;
				for (int l=j;l<=j+i;l++)
					flag[l]=1;
			}
//			cout <<"check:: "<<j<<" "<<j+i<<" "<<res<<endl;
		}
	}
	cout <<ans<<endl;
	return 0;
}