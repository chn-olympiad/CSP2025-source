#include<bits/stdc++.h>
using namespace std;
int p[999999];
long long ans=0; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int e=1;
	int o=0;
	for(int i=1;i<=a;i++){
		cin>>p[i];
		if(p[i]>1) e=2;
		if(p[i]==0) o=1;
		if(p[i]==b) ans++;
	}
	if(e==1&&o==0){
		cout<<a/2;
		return 0;
	}
	else if(e==1&&o==1){
		int ling=0,yi=0;
		for(int i=1;i<=a;i++){
			if(p[i]==0) ling++;
			else yi++;
		}
		if(b==1) cout<<yi;
		else {
			int xiang=0;
			for(int i=1;i<=a;i++){
				if(p[i]==1&&p[i+1]==1) xiang++;
			}
			cout<<xiang+ling;
		}
		return 0;
	}
	else {
		cout<<ans;
	}
	return 0;
}
