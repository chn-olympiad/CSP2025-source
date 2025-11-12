#include<iostream> 
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],Sum=0,Max=0;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Sum+=a[i];
		if(a[i]>Max){
			Max=a[i];
		}
	}
	if(Sum>Max*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
