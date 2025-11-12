#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
//unfinish!!!
//using namespace std;
std::ifstream fin("xor.in");
std::ofstream fout("xor.out");

int main(){
	int n,k;
	int ans = 0;
	fin>>n>>k;
	std::vector<int> xors(n);
	for(int &i:xors)fin>>i;
	
	for(int i = 1;i < xors.size();i++){
		xors[i] ^= xors[i - 1];
	}
	
	std::vector<int>::iterator t;
	for(std::vector<int>::iterator i = xors.begin();i < xors.end();i++){
		if(i == xors.begin() and *i == k){
			ans++;
		}else{
			for(std::vector<int>::iterator j = i + 1;j < xors.end();j++){
				if((*j ^ *i) == k){
					ans++;
					i = j - 1;
					break;
				}
			}
		}
		
	}
	
	fout<<ans;
	
	return 0;
}
