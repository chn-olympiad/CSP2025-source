#include<bits/stdc++.h>
using namespace std;
int a[100][100],chengji[1000];
long long b,c,d,jxr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>d;
	cin>>chengji[1];
	jxr=chengji[1];
	for(int i=2;i<=c*d;i++){
		cin>>chengji[i];
	}
	int jl;
	for(int j=1;j<=c*d;j++){
		for(int i=1;i<=c*d;i++){
			if(chengji[i]<chengji[i+1]){
				jl=chengji[i];
				chengji[i]=chengji[i+1];
				chengji[i+1]=jl;
			}
		}
	}
	int jl1=0;
	for(int j=1;j<=c;j++){
		if(j%2!=0){
			for(int i=1;i<=d;i++){
				jl1++;
				a[j][i]=chengji[jl1];
			}
		}else{
			for(int i=d;i>=1;i--){
				jl1++;
				a[j][i]=chengji[jl1];
			}
		}
	}
	for(int j=1;j<=c;j++){
		for(int i=1;i<=d;i++){
			if(a[j][i]==jxr){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
} 
