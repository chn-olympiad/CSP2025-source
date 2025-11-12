#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int pointR;
int numR;
int num[1005][1005];

bool cmp(int a,int b){
	return a > b;
}
int tmp;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++){
		cin>>a[i];
	}
	pointR = a[1];
	sort(a + 1,a + (n * m) + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == pointR){
			numR = i;//RµÄÃû´Î 
			break;
		}
	}
	int i = 1;
	//cout<<numR;//yes
	num[1][1] = 1;
	int tmp = 0;
	bool flag = 0;
	int j = 1;
	while(j <= m){
		tmp++;
		num[i][j] = tmp;
		if(tmp == numR){
			cout<<j<<" "<<i;
			return 0;
		}
		if(j % 2 == 0){
			flag = 1;
		}
		else{
			flag = 0;
		}
		if(i == n && flag == 0){
			j++;
		}
		else if(i == 1 && flag == 1){
			j++;
		}
		else{
			if(flag == 1){
				i--;
			}
			else{
				i++;
			}	
		}
	}
	return 0;
}
