#include<iostream>
#include<fstream>
#include<algorithm>
std::ifstream fin("polygon.in");
std::ofstream fout("polygon.out");
long long a[5005]={0};
const int mod=998244353;
long long solve(int left,int right,long long target,int minnum)
{
	if(left==right)
		{
			if(minnum<2){
			  if(a[left]>target){
				  if(target<0)
					return 2;
				else
					return 1;
					}
			  else return 0;}
			else
				return 0;
			}
	else{
	return (solve(left+1,right,target,minnum)+solve(left+1,right,target-a[left],minnum-1))%mod;
	}
}
int main()
{
int n;
fin>>n;
long long ans=0;
for(int i=0;i<n;i++){

	fin>>a[i];
	}
	std::sort(a,a+n);
	for(int i=1;i<n;i++)
	{
	  ans+=(solve(0,i-1,a[i],2))%mod;
	}
	fout<<ans%mod;
        }


