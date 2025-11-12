#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
//Çø¼ä¡¾x,y¡¿=s[y]^s[x-1] 
int n,k,a[500050],s[500050],ans=0,cnt=0;
bool b[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			b[i]=true;
			continue;
		}
		s[i]=s[i-1]^a[i];
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]) ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int m=i;m<=j;m++){
				if(b[m]) break;
			} 
			if(i==j&&s[i]==k){
				
				cnt++;
				continue;
			}
			int c=s[i]^s[j-1];
			if(c==k){
				for(int m=i;m<=j;m++){
					b[m]=true;
				}
				cnt++;
			} 
		}
	}
	cout<<cnt;
	return 0;
}
