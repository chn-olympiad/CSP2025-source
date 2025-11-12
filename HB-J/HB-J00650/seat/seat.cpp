#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int h,l,numone,nh=1,nl=1;
bool zorf=1;

bool cmp(int x,int y){
	if(x>y) return 1;
	return 0;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int arr[105]={};
	int sqq[15][15]={};
	cin>>h>>l;
	cin>>arr[1];
	numone=arr[1];
	for(int i=2;i<=h*l;i++) cin>>arr[i];
	sort(&arr[1],&arr[h*l+1],cmp);
	for(int i=1;i<=h*l;i++){
		sqq[nh][nl]=arr[i];
		if(zorf==1) nh++;
		else nh--;
		if(nh>h){
			nh--;
			zorf=0;
			nl++;
		}
		else if(nh<1){
			nh++;
			zorf=1;
			nl++;
		}
		//sqq[nh][nl]=arr[i];
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=l;j++){
			//cout<<sqq[i][j]<<" ";
			if(sqq[i][j]==numone){
				cout<<j<<" "<<i;
				break;
			}
		}
		//cout<<endl;
	}
	return 0;
}
			
