#include<bits/stdc++.h>
using namespace std;
int n,k,a[500008],s,s1,t[500008],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=1)
			s++;
	}
	if(s==n){
		if(k==0)
			cout<<s/2+n-s;
		if(k==1)
			cout<<s;	
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				s1=0;
				for(int o=0;o<i;o++){
					if(t[j+o])
						break;
					s1=a[j+o]^s1;
				}
				if(s1==k){
					//cout<<s1<<' ';
					for(int o=0;o<i;o++){
						t[j+o]=1;
						//cout<<s1<<' '<<a[j+o]<<endl;
					}
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
