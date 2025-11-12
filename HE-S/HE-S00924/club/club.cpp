#include<bits/stdc++.h>
using namespace std;

int t,n; //t为测试的组数 n为测试的人数 
int sum = 0;
int a[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i = 1;i <= t;i++){	
		cin>>n;
			for(int j = i;j <= n;j++){
				cin>>a[j];
					}
			}
	

		for(int i = 1;i <= n;i++){
			if(a[i] > a[i+1]){
				if(a[i] > a[i+2]){
					sum = a[i];
				}else{
					if(a[i] < a[i+2]){
						sum = a[i+2];
					}else{
						if(a[i+2] == a[i+1]){
							sum = a[i+2];
						}
				}
			}else{
				if(a[i+1] > a[i+2] ){
					sum = a[i];
					}else {
						if(a[i+2] > a[i+1]){
							sum = a[i+2];
						}else{
							if(a[i+2] == a[i+1]){
								sum = a[i+2];
							}
						}
					}
				}
			for(int j = 1;j <= i;j++){
				sum += sum;
			}
		}
		cout<<sum<<endl;
		
	return 0;
}
