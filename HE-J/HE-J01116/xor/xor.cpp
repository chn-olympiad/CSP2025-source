#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],s[500005];
long long cnt=0,jsq1=0,jsq2=0;
bool f1=1,f2=1,f3=1,f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)jsq1++;
		if(a[i]==0)jsq2++;
		if(a[i]!=1)f1=0;
		if(a[i]!=1&&a[i]!=0)f2=0;
		if(a[i]>255)f3=0;
		//bu shi ge men zhong wen shu ru fa qu na li le
		//you shi xor de ti
	}if(f1==1){//taihaole haiziyoujiule
		if(k>1){
			cout<<0;
		}else if(k==1){
			cout<<n;
		}else if(k==0){
			cout<<n/2;
		}return 0;
	}else if(f2==1){//wohainengzheng
		if(k>1){
			cout<<0;
		}else if(k==1){//mei ge 1 wei yi zu
			cout<<jsq1;
		}else if(k==0){//mei liang ge 1 huo mei ge 0
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1){
					a[i]=a[i+1]=0;jsq2++;
				}
			}cout<<jsq2;
		}return 0;
	}else{//shou cuo ing
		for(long long i=1;i<=n;i++){
			if(a[i]==k){
				cnt++;f[i]=1;
			}s[i]=a[i]^s[i+1];
		}for(long long i=1;i<=n;i++){
			if(f[i]==1)continue;
			for(long long j=i+1;j<=n;j++){
				if(f[j]==1)break;
				//mei ju mei ge qu jian ran hou fen bie qiu chu
				long long tt=s[i]^s[j];
				if(tt==k){
					cnt++;
					i=j+1;
					break;
				}
			}
		}cout<<cnt;
	}
	return 0;
}
