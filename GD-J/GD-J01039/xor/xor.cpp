#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(k==1){
		int total=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)total++;
		}
		if(total%2==1)cout<<n;
		else if(total%2==0){
			int dat;
			for(int i=1;i<=n;i++){
				if(a[i]==1)dat=i;
			}
			cout<<dat-1;
		}
	}
	else if(k==0){
		int total=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)total++;
		}
		if(total%2==0)cout<<n;
		else if(total%2==1){
			int dat;
			for(int i=1;i<=n;i++){
				if(a[i]==1)dat=i;
			}
			cout<<dat-1;
		}
	}
	else cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
