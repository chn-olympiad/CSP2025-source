#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int k[10001]={};
	int ans[55][55]={};
	int cnt;
	for(int i=0;i<a*b;i++){
		cin>>k[i];
	}cnt=k[0];
	sort(k,k+a*b);
	queue<int>s;
	for(int i=a*b-1;i>=0;i--){
		s.push(k[i]);
	}int i=1,l=1;
	bool p=1;
	bool first=1;
	while(!s.empty()){
		if(p){
			if(i!=a+1){
				if(i==1){
					if(first)first=0;
					else i++;
				}
				ans[i][l]=s.front();
				s.pop();
				i++;
			}else if(i==a+1){
				l++;
				i--;
				p=0;
				ans[i][l]=s.front();
				s.pop();
			}
		}else{
			if(i!=0){
				if(i==a)i--;
				ans[i][l]=s.front();
				s.pop();
				i--;
			}else if(i==0){
				i++;
				l++;
				p=1;
				ans[i][l]=s.front();
				s.pop();
			}
		}
	}
	for(int i=1;i<=a;i++){
		for(int l=1;l<=b;l++){
			if(ans[i][l]==cnt){
				cout<<l<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
