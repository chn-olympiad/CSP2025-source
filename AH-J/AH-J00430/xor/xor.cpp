#include<bits/stdc++.h>
using namespace std;
int t2(int a,int b){
	int s[102]={0},s1[102]={0};
	int i=1,j=1;
	while(a>0){
		s[i]=a%2;
		i++;
		a/=2;
	}
	i--;
	while(b>0){
		s1[j]=b%2;
		j++;
		b/=2;
	}
	j--;
	int sz[102]={0};
	for(int o=1;o<=min(i,j);o++){
		if(s[o]!=s1[o]){
			sz[o]=1;
		}
	}
	for(int u=min(i,j)+1;u<=max(i,j);u++){
		sz[u]=max(s[u],s1[u]);
	}
	int d=0;
	for(int l=max(i,j);l>=1;l--){
		d+=pow(2,l-1)*sz[l];
	}
	return d;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[100010];
	for(int d=1;d<=n;d++){
		cin>>a[d];
	}
	int l=1,h;
	int ans=0;
	while(l<=n){
		h=a[l];
		if(h==k){
			ans++;
			l++;
		}
		else{
			while(l<=n){
				h=t2(h,a[l+1]);
				l++;
				if(h==k){
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}
