#include<iostream>
#include<fstream>
#include<vector>


using std::vector;
using std::cout;
using std::endl;

std::ifstream fin("club.in");
std::ofstream fout("club.out");
int n;
int ans;
int suma[3];

void find(const vector<vector<short>> &a,int i,int sum){
	if(i == a.size()){
		ans = std::max(ans,sum);
		return;
	}
	for(int j = 0;j < 3;j++){
		if(suma[j] < (n / 2)){
			suma[j]++;
			find(a,i+1,sum + a[i][j]);
			suma[j]--;
		}
		
	}
}

void solve_one(){
	fin>>n;
	vector<vector<short>> a(n,vector<short>(3));
	for(vector<short> &i : a){
		for(short &j:i){
			fin>>j;
		}
	}
	
	ans = 0;
	for(int i = 0;i < 3;i++)suma[i] = 0;
	
	find(a,0,0);
	fout<<ans<<'\n';
}

int main(){
	int t;
	fin>>t;
	
	for(int i = 0;i < t;i++){
		solve_one();
	}
	return 0;
}
