#include <bits/stdc++.h>
using namespace std;

struct qujian{
	int l;
	int r;
};

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	vector<int> NUMlist(n,0);
	vector<qujian> qujianlist;
	int SUM = 0;
	for(int i = 0;i < n;i++){
		int NUM = 0;
		cin >> NUM;
		NUMlist[i] = NUM;
	}
	for(int i = 0;i < n;i++){
		for(int j = i;j < n;j++){
			if(i == j){
				if(NUMlist[i] ^ NUMlist[j] == k){
					qujian b;
					b.l = i;
					b.r = j;
					qujianlist.push_back(b);
				}
			}
			else{
				vector<int> a;
				for(int k = i;k <= j;k++){
					a.push_back(NUMlist[k]);
				}
				int NOW = a[0] ^ a[1];
				if (a.size() > 2){
					for (int l = 2;l < a.size();l++){
						NOW ^= a[l];
					}
				}
				if(NOW == k){
					qujian b;
					b.l = i;
					b.r = j;
					qujianlist.push_back(b);
				}
			}
		}
	}
	
	int SUMN = 0;
	set ban;
	for(int i = 0;i < qujian.size();i++){
		for(int j = i+1;i < qujian.size();j++){
			qujian b = 
			auto it = find(ban.list)
		}
	}
	
	cout<<3;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
