#include <bits/stdc++.h>
using namespace std;
long long v[100000];
long long b;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.in","w",stdout);
	long long n,m;
	long long z=1;
	long long k=1;
	long long js=0;
	cin>>n>>m;
	string a;
	cin>>a;
	for( i=1;i<=n;i++){
		cin>>v[i];
	}
	long long qq=v[1]+1-1;
	long long ww=v[n]+1-1;
	while(1){
		long long s=0;
		long long nx=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='1'){
				if(v[i]-nx>0){
					s++;
				}else{
					continue;
				}
			}else{
				s++;
			}
		}
		if(s>=m){
			js++;
		}
		b=v[k];
		v[k]=v[k-1];
		v[k-1]=b;
		k++;
		if(k==n+2){
			k=2;
		}
		if(v[1]==qq&&v[n]==ww){
			break;
		}
	}
	cout<<js%998%244%353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
