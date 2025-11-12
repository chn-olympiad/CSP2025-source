#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm> 
using namespace std;
int a[300];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int pos = 1;
	int me;
	cin>>me;
	for(int i = 2;i<=n*m;i++){
		cin>>a[i];
		if(me<a[i]){
			pos++;
		}
	}
	int line = pos/n;
	int yu = pos%n;
	if(yu>0){
		line+=1;
	}
	if(yu == 0){
		yu = n;
	}
	if(line%2 == 1){
		cout<<line<<" "<<yu;
	}
	else if(line%2 == 0){
		cout<<line<<" "<<n+1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  -yu;
	}
	return 0;
}
