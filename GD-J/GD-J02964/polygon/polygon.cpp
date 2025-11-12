#include<bits/stdc++.h>
using namespace std;
int N;
int An[5100]={};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polugon.out","W",stdout);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>An[i];
	}
	int ans=0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			for(int k=j+1;k<N;k++){
				if(An[i]+An[j]+An[k]>max(max(An[i],An[j]),max(An[i],An[j]))*2){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
