#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	long long k;
	int u,n,a[100005],num=0,r=-1;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		u=a[i];
		if(u==k){
			if(i>r){
				num++;
			}
			if(i<r){
				r=i;
			}
		}else{
			for(int j=i+1;j<n;j++){
				u=(u^a[j]);
				if(u==k){
					if(i>r){
						num++;
					}
					if((i<r && j<r) || (i>r && j>r)){
						r=j;
					}
					//cout<<i<<" "<<j<<"\n";
					
					//i++;
					break;
					
				}
				
			}
		}
		
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
}
