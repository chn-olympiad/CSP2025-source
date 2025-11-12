#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	int sum[100001];
	int a[100001];
	int b[100001];
	int c[100001];
	int temp[100001];
	cin>>t;
	int n;
	while(t--){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
}
	for(int i=0;i<n;i++){
		if(a[i]<b[i]){
			temp[i]=b[i];
		}else if(a[i]<c[i]){
			temp[i]=c[i];
		}else if(c[i]<b[i]){
			temp[i]=b[i];
		}
	}
	for(int i=0;i<n;i++)
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
