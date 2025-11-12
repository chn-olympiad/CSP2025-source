#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
int b[15][15];
int c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		if(i==1){
			c=x;
		}
		a.push_back(x);
	}
	if(n==1&&m==1){
		cout<<a[0];
		return 0;
	}
	sort(a.begin(),a.end(),cmp); 
	if(n==1){
		for(int i=0;i<m;i++){
			if(a[i]==c){
				cout<<1<<" "<<i+1;
				return 0;
			}
		}
	}
	int x=1,y=1;
	for(int i=0;i<n*m;i++){
		if(a[i]==c){
			cout<<x<<" "<<y;
			break;
		}else{
			if((i+1)%m==0){
				int cnt=(i+1)/m;
				if(cnt%2==0){
					x++;
					y=1;
				}else{
					x++;
					y=m;
				}
			}else{
				int cnt=(i+1)/m;
				if(cnt%2==0){
					y++;
				}else{
					y--;
				}
			}
		}
	}
	return 0;
}
