#include<bits/stdc++.h>

using namespace std;
//bool a[1048600],b[1048600];
int n1[500010];
//int k;
//int maxq;
//int xor(int s,int f){
//	int sum=0;
//	for(int i=s;i<f;i++){
//		for(int j=1;j<=n[i];j++){
//			if(a[0]==0)a[0]=1
//			else{
//				for(int g=0;g<)
//			}
//		}
//	}
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>n1[i];
	}
	int sum=0,mem=1000000;
	if(k==0){
		for(int i=0;i<n;i++){
			if(n1[i+1]!=mem&&i+1<n&&n1[i]==n1[i+1]){
				mem=n1[i];
				sum++;
			}
		}
	}else{
		cout<<0;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
