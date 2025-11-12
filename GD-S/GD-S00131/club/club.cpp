#include<bits/stdc++.h>
using namespace std;
struct st{
	int first_choice;
	int second_choice;
	long long first_val=0;
	long long second_val=0;
	long long fa;
};


st nums[100000];
int cmp(st a , st b){
	if(a.first_choice != b.first_choice ){
		return a.first_choice<b.first_choice;
	}
	else return a.first_val>b.first_val;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0;i<t;i++){
		long long n,tmp;
		cin >> n;
		int ch[3]={0};
		long long cnt=0;
		for(int j = 0;j<n;j++){
			for(int k = 0;k<3;k++){
				cin >> tmp;
				if(k==0){
					nums[j].first_choice = k;
					nums[j].first_val = tmp; 
				}
				
				
				else if(tmp>nums[j].first_val){
					nums[j].second_val = nums[j].first_val;
					nums[j].second_choice = nums[j].first_choice;
					
					nums[j].first_val = tmp;
					nums[j].first_choice = k;
				}
				else if(tmp>nums[j].second_val){
					
					nums[j].second_val = tmp;
					nums[j].second_choice = k;
				}
			}
			nums[j].fa = nums[j].first_val-nums[j].second_val;
		}
		sort(nums,nums+n,cmp);
		tmp = n/2;
		for(int j = 0;j<n;j++){
			if(ch[nums[j].first_choice]>=tmp){
				long long k = j,s=nums[j].first_choice,l=0,r=0,q=0;
				long long cf=nums[j].fa;
				while(k--){
					if(nums[k].fa<cf&&nums[k].first_choice == s){
						
						if(nums[k].fa<nums[j].fa){
							l = k;
							r = j;	
							cf = nums[k].fa;
							q = 1;
						}
					}
					
				}
				if(q){
					cnt += nums[l].second_val-nums[l].first_val+nums[r].first_val;
					nums[l].first_choice = nums[l].second_choice;
					ch[nums[l].second_choice]++;
				}
				else{
					cnt += nums[j].second_val;
					nums[j].first_choice = nums[j].second_choice;
					ch[nums[j].second_choice]++;
					
				}
			}
			else {
				cnt += nums[j].first_val;
				ch[nums[j].first_choice]++;
			}
		}
		cout << cnt << endl;
	}
	
	
	return 0;
} 
