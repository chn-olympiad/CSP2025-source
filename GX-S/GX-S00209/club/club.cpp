#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	
	int t,n,myd,myds=0,min=0,max=0,a;
	vector<int>ans;
	cin>>t;
	for(int p=0;p<t;p++){
		cin>>n;
		vector<vector<int>> D(n);
		vector<vector<int>> Xx(n);
		vector<int>nums(3);
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>myd;
				D[i].push_back(myd);
			}
		}
		for(int i=0;i<n;i++){
			Xx[i].push_back(D[i][0]);
			Xx[i].push_back(1);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				if(D[i][j+1]>Xx[i][0]){
					Xx[i][0]=D[i][j+1];
					Xx[i][1]=j+2;
				}
			}
		}
		for(int i=0;i<n;i++)myds+=Xx[i][0];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(Xx[i][1]==j+1){
					nums[j]++;
				}
			}
		}				
			
		for(int l=0;l<n/2;l++){
			if(nums[0]<=n/2 && nums[1]<=n/2 && nums[2]<=n/2)break;
			for(int i=0;i<3;i++){//2
				if(nums[i]>n/2){
					vector<int>hmd;
					for(int j=0;j<n;j++){
						if(Xx[j][1]==i+1){
							hmd.push_back(j);
						}
					}
					vector<int>hmd2;
					a=hmd.size();
					for(int j=0;j<a;j++){
						min=-100000;
						
						for(int k=0;k<3;k++){
							if(k!=i){
							if(D[hmd[j]][k]-D[hmd[j]][i]>min)min=D[hmd[j]][k]-D[hmd[j]][i];
							}
						}
						hmd2.push_back(min);
					}
					max=hmd2[0];
					a=hmd2.size();
					for(int j=1;j<a;j++){
						if(hmd2[j]>max){
							max=hmd2[j];
						}
					}
				
				}
		}
		myds+=max;
		}
		//ans
		
		ans.push_back(myds);
		myds=0;
	}
	for(auto x:ans)cout<<x<<" ";
	
	
	return 0;
}
