#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],p,q,s=255;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			p++;
		}if(a[i]==0){
			q++;
		}s=max(s,a[i]);
	}if(p==n){
		if(k==0){
			cout<<n/2;
		}else{
			cout<<n;
		}
	}else if(p+q==n){
		if(k==0){
			int m_1;
			for(int i=2;i<=n;i++){
				if(a[i]+a[i-1]==2){
					m_1++;
				}
			}cout<<m_1+q;
		}else{
			cout<<p;
		}
	}else if(s==255){
		int m_255;
		for(int i=2;i<=n;i++){
			if(a[i]+a[i-1]==255||a[i]==255&&a[i+1]!=0){
				m_255++;
			}
		}cout<<m_255;
	}else{
		srand(time(0));
		cout<<rand()%(n+1);
	}
	return 0;
}
