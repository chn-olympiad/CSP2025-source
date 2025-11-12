#include<bits/stdc++.h>
using namespace std;
int n,m,s,c[505],d;
long long b;
char a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a=='0') s++;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			if(c[i]==c[j]){
				c[j]=0;
				d++;
			}
		}
		d++;
	}
	b=(n-s-1)*(n-s)%998244353;
	pow(b,d);
	b%=998244353;
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
