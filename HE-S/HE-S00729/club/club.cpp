#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7+5;
int t,n;
int as[maxn][3]= {0,0,0};



int sum(){
	int sum1 = 0;
	int suma1 = 0;
	int suma2 = 0;
	int suma3 = 0;
	int sumn = 0;
	int sumn2 = 0;
	int sumn3 = 0;
	int good[maxn] = {0};
	int goodsum = 0;

	for(int j = 0;j<n;j++){
			sumn2 += as[j][1];
	}
	for(int j = 0;j<n;j++){
			sumn3 += as[j][2];
	}

	if(sumn2 == 0&&sumn3 == 0){
		for(int j = 0;j<n;j++){
			good[j] += as[j][1];
		}
		sort(good,good+n,greater<int>());
		for(int j = 0;j<n/2;j++){
			goodsum += good[j];
		}
		return goodsum;
	}


	for(int j = 0;j<n;j++){
		if(suma1<n/2 && suma2<n/2 && suma3<n/2){
			sum1 += max(max(as[j][0],as[j][1]),as[j][2]);
		}
		else if(suma1>=n/2){
			sum1 += max(as[j][1],as[j][2]);
		}
		else if(suma2>=n/2){
			sum1 += max(as[j][0],as[j][3]);
		}
		else if(suma3>=n/2){
			sum1 += max(as[j][0],as[j][1]);
		}

		if(max(max(as[j][0],as[j][1]),as[j][2]) == as[j][0]){
			suma1++;
		}
		else if(max(max(as[j][0],as[j][1]),as[j][2]) == as[j][1]){
			suma2++;
		}
		else if(max(max(as[j][0],as[j][1]),as[j][2]) == as[j][2]){
			suma3++;
		}
	}
	return sum1;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		cin>>n;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<3;j++){
				cin>>as[i][j];
			}
		}
		cout<<sum()<<endl;
		t--;
	}



	fclose(stdin);
	fclose(stdout);
	return 0;
}
