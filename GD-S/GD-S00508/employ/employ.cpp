#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<bitset>
#include <algorithm>


using std::vector;
using std::bitset;
using std::string;
using std::sort;
using std::cout;
using std::endl;

std::ifstream fin("employ.in");
std::ofstream fout("employ.out");

int ans = 0;
int now = 0;
int gamma[505] = {1};
bitset<512> used(0);

void find(const vector<int> &c,int day,const string &s,const int&n,const int &m){
	if(now >= m){
		ans += gamma[n-day];
		ans %=  998244353;
		return;
	}
	if(day == n){
		//cout<<"\n";
		return ;
	}
	
	for(int i = 0;i < n;i++){
		if(used[i])continue;
		if(c[i] > now and s[day] == '1'){
			now++;
			//cout<<day<<':'<<i<<":1 ";
			used[i] = 1;
			find(c,day+1,s,n,m);
			used[i] = 0;
			now--;
		}else{
			//cout<<day<<':'<<i<<":0 ";
			used[i] = 1;
			find(c,day+1,s,n,m);
			used[i] = 0;
		}
	}
	
}

int main(){
	int n,m;
	fin>>n>>m;
	//cout<<n<<' '<<m<<endl;
	string s;
	fin>>s;
	vector<int> c(n);
	for(int &i : c)fin>>i;
	for(int i = 1;i < n;i++){
		gamma[i] = gamma[i-1] * i % 998244353;
	}
	sort(c.begin(),c.end());
	
	find(c,0,s,n,m);
	
	fout<<ans;
	
	return 0;
}
