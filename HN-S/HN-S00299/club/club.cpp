#include<bits/stdc++.h>
using namespace std;
int result[5];
int now=0;
int max1=0;
int t,n,i,j;
long long situ[3][100000];
int fp[3]={0,0,0};

int dg(int num){
	int k,l;
	for(k=0 ; k<3 ; k++){
		fp[k]++;
		now+=situ[k][num];
		if(fp[k]<=2){
			if(num==n-1){
				if(now>max1){
					max1=now;
				}
			}
			else dg(num+1);
		}
		now-=situ[k][num];
		fp[k]--;
	}
	result[i]=max1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(i=0 ; i<t ; i++){
		cin>>n;
		for(j = 0 ; j<n ; j++){
			cin>>situ[0][j]>>situ[1][j]>>situ[2][j];
		}
		dg(0);
		max1=0;
	}
	for(int o=0 ; o<t ; o++){
		cout<<result[o]<<endl;
	}
	return 0;
}
