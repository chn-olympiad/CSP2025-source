#include<bits/stdc++.h>
using namespace std;

int n,m,arr[1000],x = 0,t = 0,cnt;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;//.行.数n与.列.数m
	while(cin>>arr[x]){
		if(x==0) cnt = arr[x];
		x++;
	}
	sort(arr,arr+x,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(arr[t] == cnt){
					cout<<i<<" "<<j;
					return 0;
				}
				t++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(arr[t] == cnt){
					cout<<i<<" "<<j;
					return 0;
				}
				t++;
			}
		}
	}
	
	return 0;
}
