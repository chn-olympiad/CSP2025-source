#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i-1]+a[i-2]>a[i]){
			sum+=i;
		}else if(a[i-1]+a[i-2]==a[i]){
			sum+=(i-3);
		}else{
			int temp=a[i-1]+a[i-2];
			if(i==3){
				continue;
			}else{
				for(int j=i-3;j>=1;j--){
					temp+=a[j];
				    if(temp>a[i]){
					    sum+=j;
					    break;
				    }else if(temp==a[i]){
					    if(j==1){
					    	break;
						}else{
							sum+=(j-1);
						}
				    }
			    }
			}
		}
	}
	cout<<sum;
	return 0;
} 
