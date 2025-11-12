#include<bits/stdc++.h>
using namespace std;
int n,m;
int mark;
int num[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>mark;//行数，列数 
	num[0] = mark;
	for(int i = 1;i < n*m;i++){
		cin>>num[i];
	}
	sort(num,num+n*m);//升序 
	int k = n*m-1;
	for(int i = 1;i <= n;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= m;j++){
				if(num[k] == mark){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
		}
		else{
			for(int j = m;j >= 1;j--){
				if(num[k] == mark){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
		}
	}
	return 0;
}
