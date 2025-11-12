#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,l=1;
	int s,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	
	for(int i=1;i<=n;i++){
		s=a[i];
		for(int j=i+1;j<=n;j++){
			if(s==k){
				sum=l;
				i++;
				}
			s=a[j]|s;
			l++;
			
			}
		}
	cout<<sum;
	
	
	fclose(stdin);
	fclose(stdout);
}
