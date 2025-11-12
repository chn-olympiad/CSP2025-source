#include<fstream>
#include<iostream>
using namespace std;
long long n;
int find(long long a[][3],long long step,long long b[3]){
	long long most=0,sum=0;
	for(int i_1=0;i_1<3;i_1++){
		if(b[i_1]+1>n/2){
			continue;
		}
		b[i_1]+=1;
		if(step<n-1){
			most=find(a,step+1,b)+a[step][i_1];
		}
		else{
			most=a[step][i_1];
		}
		if(most>sum){
			sum=most;
		}
		b[i_1]-=1;
	}
	return sum;
}
int main(){
	ifstream inFilm("club.in");
	ofstream outFilm("club.out");
	long long t;
	inFilm>>t;
	while(t--){
		inFilm>>n;
		long long a[n][3],b[3];
		for(long long i_1=0;i_1<3;i_1++){
			b[i_1]=0;
		}
		for(long long i_1=0;i_1<n;i_1++){
			for(long long i_2=0;i_2<3;i_2++){
				inFilm>>a[i_1][i_2];
			}
		}
		outFilm<<find(a,0,b)<<endl;
	}
	return 0;
}
