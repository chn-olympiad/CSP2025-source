#include <bits/stdc++.h>
using namespace std;

long long s[1000000],sum,tmp,a;
int n;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>a;
	for(int i=1;i<=n;i++)cin>>s[i];
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==a){
			sum++;
			continue;	
		}
		tmp=s[i];
		for(int j=i+1;j<=n;j++){
			tmp=tmp xor s[j];
			if(tmp == a){	
				sum++;
				i=j+1;
				break;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
