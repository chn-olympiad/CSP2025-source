#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500050];
char speci='a';
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if(speci=='a'&&a[i]==0){
			speci='b';
		}
		if((speci=='a'||speci=='b')&&a[i]!=0&&a[i]!=1){
			speci='n';
		}
	}
	cout<<speci<<"\n";
;	if (speci=='a'){
		cout<<n/2;
		return 0;
	}
	if(speci=='b'){
		if (k>1){
			cout<<'0';
		}
		if(k==1){
			int cnt=0;
			for (int i=1;i<=n;i++){
				cnt+=a[i];
			}
			cout<<cnt/2;
		}
		if (k==0){
			int cnt=0;
			for (int i=1;i<n;i++){
				if (a[i]==0){
					cnt++;
				}
				else{
					if (a[i+1]==1){
						cnt++;
						i++;
					}
				}
			}
		}
		return 0;
	}
	
	return 0;
}
//RP++
