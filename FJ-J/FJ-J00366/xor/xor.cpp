#include<bits/stdc++.h>
using namespace std;
int n,k,s,m;
int a[500010],yhh[500010];
bool b[500010],f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		yhh[i]=a[i]^yhh[i-1];
		if(a[i]==k) s++,b[i]=1;
	}
	for(int i=2;i<n;i++){
		yhh[i]=a[i];f=0;
		if(b[i])
			for(int j=i+1;j<=n;j++) yhh[j]=yhh[j-1]^a[j];
		else
			for(int j=i+1;j<=n;j++){
				if(b[j]) f=1;
				if(!f && yhh[j]==k && b[j]==0){
					f=1;s++;
					b[j]=1;
				}
				yhh[j]=yhh[j-1]^a[j];
				
			}
	}
	cout<<s;
}
