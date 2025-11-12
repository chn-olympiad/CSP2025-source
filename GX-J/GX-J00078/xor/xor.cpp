#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	long long n,k,p=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0,sum=0;
	for(int i=0;i<n;i++){
		if(a[i]==k){
			cnt=0;
			sum++;
			p=i+1;
		}
		else if(cnt<k){
			cnt^=a[i];
			if(cnt==k){
				cnt=0;
				sum++;
				p=i+1;
			}
		}else if(cnt>k){
			while(cnt>k){
				bool ok=false;
				for(int j=p;j<i;j++){
					cnt^=a[j];
					if(cnt<k){
						break;
						ok=true;
					}else if(cnt==k){
						cnt=0;
						sum++;
						p=i+1;
					}
				}
				if(ok==true) break;
				else{
					cnt=0;
					break;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
