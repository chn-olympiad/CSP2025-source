#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,r;
int CSP[11][11],AK[101];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	for(int i=1;i<=c*r;i++){
		cin>>AK[i];
	}
	int R=AK[1];
	sort(AK+1,AK+1+c*r,cmp);
	int x=1,y;
	int i=1;
	while(x<=c){
		if(x%2==0){
			y=r;
			while(y>=1){
				if(AK[i]==R){
					cout<<x<<" "<<y;
					return 0;
				}
				CSP[x][y]=AK[i];
				i++; y--;
				
			}
		}else{
			y=1;
			while(y<=r){
				if(AK[i]==R){
					cout<<x<<" "<<y;
					return 0;
				}
				CSP[x][y]=AK[i];
				i++; y++;
			}
		}
		
		x++;
	}
	return 0;
}
//试题册密码：上善若水 
//时间复杂度好像高了，补药TLE啊 
//神圣的CCF大人给点分吧 
// ___          _       _   __     ___   _____    ___
//|   |        / \     | | / /    |   | / ___ \  |   |
// | |        / _ \    | |/ /      | |  | |  | |  | |
// | |       / /_\ \   |   /       | |  | |  | |  | |
// | |      / _____ \  |   \       | |  | |  | |  | |
// | |     / /     \ \ | |\ \      | |  | |__| |  | |
//|___|   /_/       \_\|_| \_\    |___| \_____/  |___|