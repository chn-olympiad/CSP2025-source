#include<bits/stdc++.h>
using namespace std;
long long s,l=1,m,a=10,b=1,maxn=0;
long long num[1000005]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	m=s;
	while(m>=10){
		m/=10;
		l++;
	}
	for(int i=0;i<l;i++){
		num[s%a/b]++;
		if(s%a/b>maxn){
			maxn=s%a/b;
		}
		a*=10;
		b*=10;
	}
	for(int i=maxn;i>0;i--){
		if(num[i]>=1){
			for(int j=0;j<num[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
