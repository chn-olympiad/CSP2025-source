#include<bits/stdc++.h>
using namespace std;
int a[500100];
bool sum[30];
string s[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	int n,k,m=1,t,ans=0;
	long long num=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=a[i];
		m=pow(2,20);
		while(m){
			while(t<m){
				m/=2;
				s[i]+='0';
			}
			while(t>=m&&m>=1){
				t-=m;
				m/=2;
				s[i]+='1';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=21;j++)sum[j]=false;
		for(int j=i;j<=n;j++){
			num=0;
			for(int k=0;k<=20;k++){
				if(s[j][k]=='1')sum[k+1]=!sum[k+1];
			}
			for(int k=1;k<=21;k++){
				num+=(int)sum[k]*pow(2,21-k);
				if(num>k)break;
			}
			if(num==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
