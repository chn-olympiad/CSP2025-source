#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<int>l;
bool p(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a;
			l.push_back(a);
		}
	}
	b=l.at(0);
	sort(l.begin(),l.end(),p);
	for(int i=0;i<m;i++){//枚举列数
		if((i+1)%2==1){//如果是奇数，从0至m-1
			for(int j=0;j<n;j++){
				if(l[i*n+j]==b){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}	
		}
		else{
			for(int j=0;j<n;j++){
				if(l[i*n+j]==b){
					cout<<i+1<<" "<<n-j;
					return 0;
				}
			}
		}
	}
}