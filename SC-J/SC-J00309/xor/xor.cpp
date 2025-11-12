#include <bits/stdc++.h>
using namespace std;
long long n,k,cnt,a[500005],v[500005],q,w,asd,ans;
string e;
string wer(int z){
	for (int i=0;i<=30;i++) e[i]='2';
	int r=0;
	while(z!=0){
		e[r]=char(z%2+'0');
		z/=2;
		r++;
	}
	return e;
}
int qwe(int x,int y){
	if(y==0) return 1;
	int r=1;
	for (int i=1;i<=y;i++){
		r*=2;
	}
	return r;
}
int qw(string x,string y){
	int t=0;
	while(x[t]!='2'&&y[t]!='2'){
		if(x[t]=='2') x[t]=y[t];
		else {
			if(x[t]==y[t]) x[t]='0';
			else x[t]='1';
		}
		t++;
	}
	int r=0;
	for (int i=t-1,j=0;i>=0;i--,j++){
		if(x[t]=='1') r+=qwe(2,j);
	}
	return r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if(k==a[i]) v[i]=1,cnt++,q++;
	}
	w=2;
	while(1){
		for (int i=1;i<=n;i++){
			asd=0;
			for (int j=0;j<w;j++){
				if(v[i+j]==1){
					asd=1;
					break;
				}  
			}
			if(asd==1){
				for (int j=0;j<w;j++) v[i+j]=1,q++;
			}
			else {
				for (int j=1;j<w;j++){
					if(j==1) ans=qw(wer(a[i]),wer(a[i+1]));
					else ans=qw(wer(ans),wer(a[i+j]));
				}
				if(ans==k){
					for (int j=0;j<w;j++) v[i+j]=1,q++;
					cnt++;
				}
			}
		}
		if(q==n) break;
		w++;
	}
	cout<<cnt;
	return 0;
} 