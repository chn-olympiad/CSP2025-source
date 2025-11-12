#include<bits/stdc++.h>
using namespace std;
int n,m,a,x[20][20],ans,xx=1,yy=1;
vector<int> num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a;
		if(i==1){
			ans=a;
		}
		num.push_back(a);
	}
	sort(num.begin(),num.end());
	while(num.size()){
		if(num.size()){
			for(int i=1;i<=n;i++){
				x[i][yy]=num[num.size()-1];
				if(num[num.size()-1]==ans){
					cout<<yy<<" "<<i;
					return 0;
				}
				num.erase(num.end()-1);
			}
			yy++;
		}
		if(num.size()){
			for(int i=n;i>=1;i--){
				x[i][yy]=num[num.size()-1];
				if(num[num.size()-1]==ans){
					cout<<yy<<" "<<i;
					return 0;
				}
				num.erase(num.end()-1);
			}
			yy++;
		}
	}
	return 0;
} //2 2 99 98 100 97
