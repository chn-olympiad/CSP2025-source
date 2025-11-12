#include<bits/stdc++.h>
using namespace std;
int a[5005],n,b[5005]={0};
long long ans;
bool m[5005]={false};
void k(int l,int ma,int h){
	if(l==n)return;
	for(int i=0;i<n;i++){
		if(!m[i]){
			if(l>2){
				if(h>ma*2){
					for(int j=0;j<n;j++)
						if(a[j]==ma)
							ans+=b[j];
					ans%=998244353;
				}
			}
			m[i]=true;
			if(a[i]>ma)
				k(l+1,a[i],h+a[i]);
			else
				if(l<2)
					k(l+1,ma,h+a[i]);
			m[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		for(int j=0;j<i+1;j++){
			if(a[j]<a[i])b[i]++;
			else b[j]++;
		}
	}
	k(0,0,0);
	cout << ans << endl;
	return 0;
}
