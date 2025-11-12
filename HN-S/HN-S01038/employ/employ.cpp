#include<bits/stdc++.h>
using namespace std;
char a1[510];
long long a2[510],a3,a4,a5[510];
long long s1(long long a,long long b){
	long long i,j=1,k=1;
	if(b==a4){
		for(i=a;i<=a3;i++){
			j*=k;
			k++;
			j%=998244353;
		}
		return j;
	}
	if(a>a3){
		return 0;
	}
	j=0;
	for(i=1;i<=a3;i++){
		if(a2[i]==0){
			a2[i]=1;
			k=0;
			if(((a-1-b)<a5[i])&&(a1[a-1]=='1')){
				k=1;
			}
			j+=s1(a+1,b+k);
			a2[i]=0;
		}
	}
	j%=998244353;
	return j;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long a=1,b,c,d,e,f,g,h,i,j,k;
	cin>>a3>>a4>>a1;
	for(i=1;i<=a3;i++){
		cin>>a5[i];
	}
	cout<<s1(1,0);
	return 0;
}
