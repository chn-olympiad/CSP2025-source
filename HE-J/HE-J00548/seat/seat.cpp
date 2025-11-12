#include<bits/stdc++.h>
using namespace std;
int people[105],p[12][12];
bool self[105] = {0,1,0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int q,w;
	cin>>q>>w;
	int e = q*w;
	for(int i = 1;i <= e;i++){
		cin>>people[i];
	}
	int R = people[1];
	for(int i = 1;i <= e;i++){
		for(int j = 1;j <= e-i;j++){
			if(people[j] < people[j+1]){
				swap(people[j],people[j+1]);
				swap(self[j],self[j+1]);
			}
		}
	}
	int x = 1,y = 1,ii = 1;
	for(int i = 1;i <= q;i++){
		for(int j = 1;j <= w;j++){
			p[i][j] = people[ii];
			ii++;
		}
		if(i==ii) break;
		i++;
		for(int j = w;j >= 1;j--){
			p[i][j] = people[ii];
			ii++;	
		}
	}
	
	for(int i = 1;i <= q;i++){
		for(int j = 1;j <= w;j++){
			if(p[i][j]==R){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
}
