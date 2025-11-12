#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
long long sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	if(n<=3 && a[3]<=10){
		if(a[1] + a[2] > a[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
//		cout<<b[i]<<" ";
	}
//	cout<<endl;
	
	for(int i=2;i<=n;i++){//加入新元素 
		for(int j=i-2;j>=0;j--){
			if(b[i] - b[j] > a[i+1]){
				for(int k=i+1;k<=n;k++){
					
					if(b[i] - b[j] > a[k]){
//						cout<<j+1<<' '<<i<<' '<<k<<endl;
						sum = (sum + 1) % 998244353;
						
						int chaju=b[i]-b[j]-a[k];
						for(int op=j+1;op<i;op++){
							for(int opp=op+1;opp<i;opp++){
								if(b[opp] - b[op] < chaju){
									sum = (sum + 1) % 998244353;
//									cout<<j+1<<' '<<i<<' '<<k<<"除了"<<op+1<<" "<<opp<<endl;
								}
							}
						}
					}
					else if(b[i] - b[j] < a[k]){
						break;
					}
				}
			}
			
		}
	}
	cout<<sum;
	return 0;
} 
