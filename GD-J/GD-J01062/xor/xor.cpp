#include<bits/stdc++.h>
using namespace std;
int n,k,m,a[1000001],pre[1000001];
int s1=0,s2=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			f=0;
			s1++;
		}else{
			s2++;
		}
	}
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
    if(f) cout<<n;
    else{
    	if(k==1) cout<<s2;
    	else cout<<s1;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
