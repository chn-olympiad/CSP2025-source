#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,m,h=0,ar;cin>>n>>m;
	long long arr[1000000]={ };//arr2[n+1][m+1];
	for(int a=0;a<m*n;a++){
		cin>>arr[a];
		}
	arr[0]=ar;
	for(int s=0;s<n;s++){
		for(int q=s+1;q<n*m;q++){
			if(arr[s]<arr[q]){
				h=arr[s],arr[s]=arr[q],arr[q]=h;
				}
			}
		}

		for(int i=n;i>0;i--){
			if(ar==arr[q]){
				cout<<i<<' '<<m;
				}
			else if(arr[q]==ar){
				cout<<i<<' '<<m;
			 }
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
