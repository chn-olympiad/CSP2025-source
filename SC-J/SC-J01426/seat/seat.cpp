#include<bits/stdc++.h>
using namespace std;
int n,m,a;//n行 m列 
vector<int>num;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			if(i==1&&j==1)a=x;
			num.push_back(x);
		}
	}
	sort(num.begin(),num.end(),cmp);
	
	for(int i=1;i<=m;i++){
		int ch=pow(-1,i+1);
		for(int j=((i%2==1)?1:n),add=1;1<=j&&j<=n;j+=ch,add++){
			int k=(i-1)*n+add;
			if(num[k-1]==a){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}