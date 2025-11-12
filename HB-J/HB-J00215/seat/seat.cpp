//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
constexpr const int N=10,M=10;
int n,m,score,a[N*M+1];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	score=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1,j=1,cnt=1,mode=0;cnt<=n*m;cnt++){
		if(a[cnt]==score){
			cout<<j<<' '<<i<<'\n';
			break;
		}
		switch(mode){
			case 0:
				if(i<n){
					i++;
					break;
				}else{
					j++;
					mode=1;
					break;
				}
			case 1:
				if(1<i){
					i--;
					break;
				}else{
					j++;
					mode=0;
					break;
				}
		}
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
