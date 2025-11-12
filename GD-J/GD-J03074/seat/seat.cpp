#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int a[10001]; 

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	int total=n*m;
	int R=0;
	
	for(int i=1;i<=total;i++){
		cin>>a[i];
	}
	R=a[1];
	
	sort(a+1,a+1+total,cmp);
	
    int Rp=0;
	for(int i=1;i<=total;i++){
		if(R==a[i]){
			Rp=i;
			break;
		}
	}
	
	int l=(Rp+n-1)/n;
	int ll=Rp%n;

	int x=l,y=0;
	if(l%2){
		if(ll==0){
			y=n;
		}else{
			y=ll;
		}
	}else{
		if(ll==0){
			y=1;
		}else{
			y=n-ll+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
