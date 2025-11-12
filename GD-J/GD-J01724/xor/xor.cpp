#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,b[25],c[25],ans=500005,x,num;
void y(long long o,long long p){
	long long d[25],f[25],e[25],h,k,g,l;
	cout<<o<<" "<<p<<endl;
	while(o){
		cout<<o;
		cout<<o%2<<" ";
		d[++k]=o%2;
		cout<<o%2<<" ";
		o/=2;
	}
	cout<<o<<endl;
	while(p){
		f[++h]=p%2;
		cout<<p%2<<" ";
		p/=2;
	}
	cout<<p<<endl;
/*	for(int i=k;i>=1;i--){
		cout<<d[i]<<" ";
	}
	cout<<endl;
	for(int i=h;i>=1;i--){
		cout<<f[i]<<" ";
	}
	cout<<endl;*/
	for(int i=max(k,h);i>=1;i--){
		if(!(d[i]==f[i])){
			e[++g]=1;
		}else{
			e[++g]=0;
		}
	}
	for(int i=1,j=1;i<=g;i++,j*=2){
		l+=j*e[i];
	}
	cout<< l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	y(a[1],a[2]);
/*	for(int i=1;i<=n;i++){
		num=0;
		cout<<1;
		for(int j=i;j<=n;j++){
			if(y(m,a[j])==x){
				num++;
			}
			cout<<1;
			m=y(m,a[j]);
		}
		cout<<1;
		ans=min(num,ans);
	}*/
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
//#Shang4Shan3Ruo6Shui4
