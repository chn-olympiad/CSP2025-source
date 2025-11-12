//GZ-S00296 贵阳市第六中学 沈彬耀

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct note{
	int v = -1;
	int i = 0;
};

int main(){
	ifstream fin("club.in");
	ofstream fout("club.out");
	int t = 0;
	fin>>t;
	for(int T = 1; T<=t; ++T){
		int n;
		fin>>n;
		note b[4][n + 2];

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= 3; ++j){
				fin>>b[j][i].v;
				b[j][i].i = i;
				for(int k = 1; k < i; ++k){
					if(b[j][i].v > b[j][k].v){
						for(int s = i + 1; s > k; --s){
							b[j][s] = b[j][s - 1];
						}
						b[j][k] = b[j][i + 1];
						b[j][i + 1].v = -1;
						break;
					}
				}
			}
		}
		bool flag[n + 1];
		int m[4];
		memset(m, 0, sizeof(m));
		memset(flag, 0, sizeof(flag));
		int sum = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= 3; ++j){
				if(flag[b[j][i].i] != 1 && m[j] <= n/2){
					sum += b[j][i].v;
					flag[b[j][i].i] = 1;
					m[j] += 1;
				}
			}
		}
		fout<<sum<<endl;
	}
	fin.close();
	fout.close();
	return 0;
} ;
