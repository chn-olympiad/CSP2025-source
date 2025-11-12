#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int tmp=0,bc=0;
	for(int k=3;k<=n;k++){
		for(int i=0;i<n;i++){
			bc=0;
			bc+=a[i];
			int max=a[i];
			if(i+k>n)break;
			for(int j=i+1;j<i+k;j++){
				bc+=a[j];
				max=a[j];
			}
			if(bc>2*max)tmp++;
	 }
	}
	cout<<tmp+tmp/2;
	return 0;
}