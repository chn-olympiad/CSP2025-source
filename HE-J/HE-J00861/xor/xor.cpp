#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x[100005];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>x[i];
	} 
	if(k==0){
		cout<<n;
	}
	else{
		int num_zero=0;
		int num_one=0;
		int answer=0;
		for(int i=0;i<n;i++){
			if(x[i]==0){
				num_zero++;
			}
			else{
				num_one++;
			}
			if(num_zero%2!=0 && num_zero%2!=0 && num_zero!=0 && num_one!=0){
				answer++;
				num_zero=0;
				num_one=0;
			}
		}
		cout<<answer;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
