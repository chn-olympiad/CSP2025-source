#include <bits/stdc++.h>
using namespace std;
long long a[11];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int ent=0;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[n[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		
		while(a[i]>0){
			if(a[i]%10==0){
				printf("%d%d%d%d%d%d%d%d%d%d",i,i,i,i,i,i,i,i,i,i);
				a[i]-=10;
			}else{
				printf("%d",i);
				a[i]--;
			}
		}
	}
	
	return 0;
}
