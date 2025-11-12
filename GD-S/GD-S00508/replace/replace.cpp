#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <utility>


using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;

std::ifstream fin("replace.in");
std::ofstream fout("replace.out");

int problem_solve(const vector<pair<string,string>> &s,string &problem1,string &problem2){
	int ans = 0;
	int f1,f2,t;
	bool flag;
	string ts = problem1;
	for(const pair<string,string>&i:s){
		while(1){
			f1 = problem1.find(i.first);
			if(f1 != -1){
				//cout<<problem.first<<' '<<problem.second<<"  "<<i.first<<' '<<i.second<<endl;
				f2 = problem2.find(i.second);
				if(f1 == f2){
					t = f1+i.first.size();
					if(t == problem1.size()){
						ans++;
						break;
					}
					flag = true;
					for(int i = 0;i < ts.size();i++){
						if(i == f1){
							i = t;
						}
						if(ts[i] != problem2[i]){
							flag = false;
							break;
						}
					}
					if(flag){
						ans++;
						break;
					}
				}
				problem1[f1] = 1;
			}else{
				break;
			}
		}
	}
	return ans;
}

int main(){
	int n,q;
	fin>>n>>q;
	vector<pair<string,string>> s(n);
	pair<string,string> problem;
	for(pair<string,string> &i:s){
		fin>>i.first>>i.second;
	}
	for(int i = 0;i < q;i++){
		fin>>problem.first>>problem.second;
		fout<<problem_solve(s,problem.first,problem.second)<<'\n';
	}
	return 0;
}
