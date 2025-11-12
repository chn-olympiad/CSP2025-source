#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int seat;
bool isup=false;
void func(int seat,int cnt,int x,int y){
	if(cnt>=seat){
		cout<<x<<" "<<y;
		return;
	}
	if(cnt!=1&&(y==n||y==1)){
		x++;
		cnt++;
		if(cnt>=seat){
			cout<<x<<" "<<y;
			return;
		}
		if(isup){
			isup=false;
		}
		else{
			isup=true;
		}
	}
	if(isup){
		y--;
	}
	else{
		y++;
	}
	func(seat,cnt+1,x,y);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	vector<int> a(n*m+1,0);
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	int score=a[1];
	sort(a.begin()+1,a.end(),[](int a,int b)->bool{
		return a>b;
	});
	for(int i=0;i<n*m;i++){
		if(a[i]==score){
			seat=i;
			break;
		}
	}
	func(seat,1,1,1); 
	return 0;
}
