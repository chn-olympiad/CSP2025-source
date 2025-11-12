#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n]={};
	int earr[n]={};
	int num=0;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==m){
			sum++;
			earr[num]=i;
			num++;
		}
	}
	sort(earr,earr+num);
	for(int i=2;i<=n;i++){
		for(int j=0;j<n;j++){
			int ds=a[j];
			bool falg=true;
			for(int k=0;i<num;k++){
				if(falg){
					for(int e=j;e<j+i;e++){
						if(earr[k]==e){
							falg=false;
							break;
						}
					}
				}else{
					break;
				}
			}
			if(falg){
				for(int k=1;k<i;k++){
					ds=ds^a[j+k];
				}
				if(ds==m){
					sum++;
				}
			}
		}
	}
	cout<<sum/2<<endl;
	return 0;
}

