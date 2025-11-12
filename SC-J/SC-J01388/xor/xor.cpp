#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==1){
		int h=0;
		for(int i=1;i<=n;i++){
			int a;cin>>a;
			if(a==1)h++;
		}
		cout<<h; 
	}
	else{
		int h=0;
		for(int i=1;i<=n;i++){
			int a;cin>>a;
			for(int i=1;i<=n;i++){
				if(a==0)h++;
			}
		cout<<h;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 