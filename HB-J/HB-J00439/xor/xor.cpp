#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long n,k,cnt,sum,f=1;
long long a[N];
vector<long long> c[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])cnt++;
		if(a[i]>1)f=0;
	}
	if(k==0 && f)cout<<cnt/2;
	else if(k==1 && f)cout<<cnt;
	else{
		for(int i=1;i<=n;i++){
			int tmp=0;
			for(int j=i;j<=n;j++){
				tmp=tmp^a[j];
				c[i].push_back(tmp);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=0,len=c[i].size();j<len;j++)
				if(c[i][j]==k){
					sum++;
					i=i+j;
					break;
				}
		cout<<sum;
	}
	
	return 0;
}
