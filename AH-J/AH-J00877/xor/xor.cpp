#include<bits/stdc++.h>
using namespace std;
long long a[510000],b[510000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k; 
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	long long he=0;
	for(long long i=1;i<=n;i++){
		he=0;
		for(long long j=i;j<=n;j++){
			if(i==j){
				he=he+a[i];
			}else{
				he=he^a[j];
			}
			if(he==k){
				cnt++;
		        for(int k=i;k<=j;k++){
					if(b[k]==0){
						b[k]=a[k];
					}else{
						cnt--;
						break;
					}
				}
			    he=0;
			    i=j;
			    break;
			}
		}
	}
	cout<<cnt;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
