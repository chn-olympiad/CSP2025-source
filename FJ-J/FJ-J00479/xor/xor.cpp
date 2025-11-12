#include<bits/stdc++.h>
using namespace std;
int x[500005];
bool check[500005]={true};
int yu(int a,int b){
	int num=0;
	vector<int> aa;
	vector<int> bb;
	while(a!=0||b!=0){
		if(a==0){
			int tmp=b%2;
			aa.push_back(0);
			bb.push_back(tmp);
			b=b/2;
			continue;
		}
		if(b==0){
			int tmp=a%2;
			aa.push_back(tmp);
			bb.push_back(0);
			a=a/2;
			continue;
		}
		int tmp1=a%2,tmp2=b%2;
		aa.push_back(tmp1);
		bb.push_back(tmp2);
		a=a/2,b=b/2;
	}
	for(int i=aa.size()-1;i>=0;i--){
		num*=2;
		if(aa[i]!=bb[i]){
			num=num+1;
		}
	}
	return num;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		check[i]=false;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(check[i]==true){
				break;
			}
			else{
				int sum=x[i];
				if(i!=j){
					int flag=0;
					for(int l=i+1;l<=j;l++){
						if(check[l]==true){
							flag=l;
							break;
						}
					}
					if(flag==0){
						for(int l=i+1;l<=j;l++){
							sum=yu(x[l],sum);
							check[l]=true;
						}
						if(sum==k){
							ans++;
							/*cout<<endl<<ans<<" ";
							for(int l=i;l<=j;l++){
								cout<<x[l]<<" "<<l<<" ";*/
						}
						else{
							for(int l=i;l<=j;l++){
								check[l]=false;
							}
						}
					}
					else{
						break;
					}
					
				}
				if(i==j){
					if(x[i]==k&&check[i]==false){
						check[i]=true;
						ans++;
						/*cout<<endl<<ans<<" ";
						cout<<x[i]<<" "<<i<<" ";*/	
					}
				}
			}
		}
	}		
	cout<<ans;
	return 0;
}
