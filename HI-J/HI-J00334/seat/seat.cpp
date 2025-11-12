#include <bits/stdc++.h>
using namespace std;
int a[1000000];
vector <int> b;

int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,z,w;cin>>n>>m;z=m*n;
	for(int i=1;i<=z;i++){
		cin>>a[i];
		//int ls;cin>>ls;b.push_back(ls);
	}
	//x=b.front();
	x=a[1];
	sort(a+1,a+1+z,greater<int>());
	for(int i=1;i<=z;i++){	if(a[i]==x){w=i;break;
	}
	}	
//	cout<<w<<" ";
	if(m>=w){
		cout<<1<<" "<<w;return 0;
	}
	
	else {int ll;
		if((w/m)%m==0){
		
		cout<<w/m<<" ";ll=w/m;}
		if((w/m)%m!=0){
		cout<<w/m+1<<" "; ll=w/m+1;}
	//	cout<<ll<<" "; 
	if(ll%2==0){
		int shou=ll*m,sum=0;
	//	cout<<shou<<" ";
		for(int i=shou;i>=shou-m;i--){
			sum++;
			if(i==w){
			cout<<sum;return 0;}
		}
	}
	if(ll%2!=0){
			int wei=ll*m,sum=0;
	//	cout<<wei<<" ";
		for(int i=wei-m+1;i<=wei;i++){
			sum++;
			if(i==w){
			cout<<sum;return 0;}
		}
		
	}
		
	}

return 0;
}
