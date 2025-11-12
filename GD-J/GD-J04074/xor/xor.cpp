#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010],ans,pos,flag,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pos=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			int flag=0;
			for(int l=pos;l<i;l++){
				int ansx=0;
				for(int p=l;p<i;p++){
					cnt=a[p];
					for(int j=p+1;j<i;j++){
						cnt^=a[j];
						if(cnt==k){
							ansx++;
							p=j;
							break;
						}
					}
				}
				flag=max(flag,ansx);
			} 
			ans+=flag;
			pos=i+1;
		}
	}
	int flag=0;
	for(int l=pos;l<=n;l++){
		int ansx=0;
		for(int p=l;p<=n;p++){
			cnt=a[p];
			for(int j=p+1;j<=n;j++){
				cnt^=a[j];
				if(cnt==k){
					ansx++;
					p=j;
					break;
				}
			}
		}
		flag=max(flag,ansx);
	}
	ans+=flag;
	cout<<ans;
	return 0;
}

