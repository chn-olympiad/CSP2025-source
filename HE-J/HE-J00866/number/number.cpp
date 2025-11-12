#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdin);
	int s;
	int ans;
	int sum=0;
	cin>>s;
	for(int i=0;i<=10;i++){
		ans++;
		if(ans==s){
			for(int j=0;j=s;j--){
				if(j>=i){
					sum+=j;
					cout<<sum;
					break;
				}
			}
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
