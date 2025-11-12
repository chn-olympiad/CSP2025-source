#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0;i<t;i++){
		int n,res = 0;
		int ji[4] = {0,0,0,0};
		cin >> n;
		int mo[n+1][3];
		int mt[n+1][3];
		int mr[n+1][3];
	    int cha[n+1]= {0};
	    
		for(int i = 1;i<=n;i++){
			int z[4];
			cin >> z[1]>>z[2]>>z[3];
			if(z[1]>=z[2]&&z[1]>=z[3]){
				mo[i][1] = z[1];
				mo[i][2] = 1;
				if(z[2]>=z[3]){
					mt[i][1] = z[2];
					mt[i][2] = 2;
					mr[i][1] = z[3];
					mr[i][2] = 3;
				}
				else{
					mt[i][1] = z[3];
					mt[i][2] = 3;
					mr[i][1] = z[2];
					mr[i][2] = 2;
				}
			}
			if(z[2]>=z[1]&&z[2]>=z[3]){
				mo[i][1] = z[2];
				mo[i][2] = 2;
				if(z[1]>=z[3]){
					mt[i][1] = z[1];
					mt[i][2] = 1;
					mr[i][1] = z[3];
					mr[i][2] = 3;
				}
				else{
					mt[i][1] = z[3];
					mt[i][2] = 3;
					mr[i][1] = z[1];
					mr[i][2] = 1;
				}
			}
			if(z[3]>=z[2]&&z[3]>=z[1]){
				mo[i][1] = z[3];
				mo[i][2] = 3;
				if(z[1]>=z[2]){
					mt[i][1] = z[1];
					mt[i][2] = 1;
					mr[i][1] = z[2];
					mr[i][2] = 2;
				}
				else{
					mt[i][1] = z[2];
					mt[i][2] = 2;
					mr[i][1] = z[1];
					mr[i][2] = 1;
				}
			}
			res += mo[i][1];
			ji[mo[i][2]] ++;
			cha[i] = mo[i][1] - mt[i][1];
		}
		sort(cha+1,cha+n);
		int pp = max(max(ji[1],ji[2]),ji[3]);
		if(pp > n/2){
			for(int y = 1;y<=pp-n/2;y++){
				res -= cha[y];
			}
		}	
		cout << res<<endl;
	}
return 0;	
}
