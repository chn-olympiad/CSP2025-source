#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		if(n%2!=0){
			return;
		}else{
			int j;
			cin>>j;
			int m=j1+j2+j3;
			for(int j=3;j>=n;j--){
				if(j>n/2){
					return;
				}else{
					cout<<m<<endl;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
