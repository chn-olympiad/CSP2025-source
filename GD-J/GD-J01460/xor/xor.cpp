#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,k,ans=0,xo,c=0;
bool fl[500005];
string ejz(long long s){
	string aa;
	while(s>1){
		aa+=('0'+s%2);
		s/=2;
		c++;
	}aa+='1';
	return aa;
}
long long yh(long long q,long long w){
	int x=1;
	long long anss=0;
	string q1=ejz(q);
	long long c1=c+1;
	string w1=ejz(w);
	long long c2=c+1;
	if(c1>=c2){
		for(int i=0;i<c2;i++){
			if(q1[i]!=w1[i]){
				anss+=x;
			}x*=2;
		}for(int i=c2;i<c1;i++){
			if(q1[i]=='1'){
				anss+=x;
			}x*=2;
		}
	}else{
		for(int i=0;i<c1;i++){
			if(q1[i]!=w1[i]){
				anss+=x;
			}x*=2;
		}for(int i=c1;i<c2;i++){
			if(w1[i]=='1'){
				anss+=x;
			}x*=2;
		}
	}return anss;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			fl[i]=1;
		}
	}for(int i=0;i<n;i++){
		if(fl[i]==0){
			xo=a[i];
			for(int j=i+1;j<n;j++){
				xo=yh(xo,a[j]);
				if(fl[j]==1){
					break;
				}
				if(xo==k){
					ans++;
					for(int p=i;p<=j;p++){
						fl[p]=1;
					}xo=0;
					break;
				}
			}xo=0;
		}
	}cout<<ans;
	return 0;
}
