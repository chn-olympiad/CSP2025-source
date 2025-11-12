#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<unordered_map>
//unfinish!!!

std::ifstream fin("polygon.in");
std::ofstream fout("polygon.out");

int ts[505];

void sum_greater(std::vector<int>&anss,const int&ansi,const std::vector<int>&a,int i,int sum,const int&k){
	if(sum > k){
		if(ts[i] == 0){
			ts[i] = 1;
			for(int j = 0;j < i;j++){
				ts[i] = ts[i] * 2 % 998244353;
			}
		}
		anss[ansi] += ts[i];
		anss[ansi] %= 998244353;
		return ;
	}
	for(int j = i - 1;j >= 0;j--){
		//if(ans1s[j] != 0 and a[j] * 2 > (k - sum)){
		//	ans1s[ans1i] += ans1s[j];
		//	ans1s[ans1i] %= 998244353;
		//}else{
			sum_greater(anss,ansi,a,j,sum+a[j],k);
		//}
	}
}

int main(){
	int n;
	fin>>n;
	std::vector<int> a(n);
	std::vector<int> anss(n,0);
	for(int &i:a)fin>>i;
	std::sort(a.begin(),a.end());
	
	for(int i = 2;i < a.size();i++){
		sum_greater(anss,i,a,i,0,a[i]);
		//std::cout<<i+1<<"finish"<<std::endl;
	}
	
	int ans1 = 0;
	for(int &i:anss){
		//std::cout<<i<<" ";
		ans1 += i;
		ans1 %= 998244353;
	}
	
	fout<<ans1;
	
	return 0;
}
