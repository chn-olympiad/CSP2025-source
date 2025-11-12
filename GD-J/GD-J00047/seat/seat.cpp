#include <bits/stdc++.h>
using namespace std;
long long n,m,score[150],current_id,target,layout[150][150];
long long j = 1;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> score[i];
	}
	long long id= 1;
	target = score[1];
	sort(score + 1,score + 1 + n*m,cmp);
	for(int i = 1;j <= m;i ++){
		
		layout[j][i] = score[id];
		id ++;
		if(i == n){
			j ++;
			for(;i >= 1;i --){
				layout[j][i] = score[id];
				id++;
			}
			j++;
		} 
	}

	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			if(layout[j][i] == target) cout << j <<" " << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
