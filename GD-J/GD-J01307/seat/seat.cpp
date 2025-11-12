#include<bits/stdc++.h>
using namespace std;
int a[15][15],score[150];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int l=n*m;
	for(int i = 0;i < l;i++){
		cin >> score[i];
	}
	int s0=score[0];
	sort(score,score+l,cmp);
	int t=0;
	for(int i = 0;i < n;i++){
		if(i%2==0){
			for(int j = 0;j < m;j++){
				a[j][i]=score[t];
				t++;
			}
		} else {
			for(int j = m-1;j >= 0;j--){
				a[j][i]=score[t];
				t++;
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(a[i][j]==s0){
				cout << j+1 << " " << i+1;
				return 0;
			}
		}
	}
} 
