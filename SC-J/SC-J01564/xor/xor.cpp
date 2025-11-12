#include<bits/stdc++.h>
using namespace std;

int a[500005],s[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cmp=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cmp++;
			s[i]=1;
		}
	}

	for(int i=1;i<=n;i++){
		int tmp=a[i],z=0;
		for(int j=i+1;j<n;j++){
			if(tmp<k ){
				tmp+=a[j];
				if(tmp==k && s[j]!=1){
					s[i]=1;
					s[j]=1;
					cmp++;
					z=1;
					break;
				}else if(s[j]==1){
					break;
				}
			}else if(tmp>k){
				tmp-=a[j];
				if(tmp==k && s[j]!=1){
					s[i]=1;
					s[j]=1;
					cmp++;
					z=1;
					break;
				}else if(s[j]==1){
					break;
				}
			}
		}
		if(z==0){
			tmp=0-a[i];
			for(int j=i+1;j<n;j++){
				if(tmp<k ){
					tmp+=a[j];
					if(tmp==k && s[j]!=1){
		 				s[i]=1;
						s[j]=1;
						cmp++;
						z=1;
						break;
					}else if(s[j]==1){
						break;
					}
				}else if(tmp>k){
					tmp-=a[j];
					if(tmp==k && s[j]!=1){
						s[i]=1;
						s[j]=1;
						cmp++;
						z=1;
						break;
					}else if(s[j]==1){
						break;
					}
				}	
			}
		}
	}
	cout<<cmp;
	return 0; 
}