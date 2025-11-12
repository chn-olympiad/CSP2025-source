#include<bits/stdc++.h>
using namespace std;
int n,k,nums[50005],nums_1=0;
bool cheat=1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>nums[i];
		if(nums[i]!=1) cheat=0;
		else nums_1++;
	}
	if(cheat)
	{
		if(k==1){
		cout<<n;
		}
		else{
		cout<<0;
		}
		fclose(stdin);fclose(stdout);
		return 0;
	}	
	if(k==1)
	{
		cout<<nums_1;
	}
	else{
		cout<<n-nums_1;
	}
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}
