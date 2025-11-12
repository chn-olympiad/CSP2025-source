#include <bits/stdc++.h>
using namespace std;
bool sort_rule(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int pn = n*m;
	vector<int> score(pn);
	int a1;
	for(int i = 0;i<pn;i++){
		cin>>score[i];
	}
	
	a1 = score[0];
	int a1_j = 0;
	sort(score.begin(),score.end(),sort_rule);
	for(int i = 0;i<pn;i++){
		if(score[i] == a1){
			a1_j = i+1;
			break;
		}
	}
	int x,y;
	x = ceil((a1_j / double(n)));
	if(x%2 == 0){
		y = n+1-(a1_j % n == 0? n: (a1_j % n));
	}else{
		y = a1_j % n == 0? n: (a1_j % n);
		
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}