#include <bits/stdc++.h>
using namespace std;

int a[500005],state[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,cnt=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}

	
	int crt=0,l,r;
	bool break_flag=0;
	for(int length=1;length<=n;length++){
		for (int i=1;i<=n+1-length;i++){
			l=i;r=i-1+length;
			crt=0;
			break_flag=0;
			for (int j=l;j<=r;j++){
				if (state[j]==0){
					crt^=a[j];
				}
				else{
					i=j;
					break_flag=1;
					break;
				}
				
			}
			if (break_flag) continue; 
			if (crt==k){
				cnt++;
				for (int j=l;j<=r;j++){
					state[j]=1;
				}
			}
			
		}
		
	}
	cout<<cnt;

	return 0;
}
