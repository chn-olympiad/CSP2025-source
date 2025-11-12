#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(NULL));
int N=1000,M=20000,K=10,C=1e9;
int main(){
	for(int i=1;i<=100;i++){
		system("cls");
		cout<<"Checking "<<i<<" of 100"<<endl;
		ofstream fout("road.in");
		int n=rnd()%N+1,m=rnd()%M+1,k=rnd()%K;
		if(m<n-1){
			m=n-1;
		}
		for(int i=1;i<n;i++){
			fout<<i<<" "<<rnd()%i+1<<endl;
		}
		for(int i=n;i<=m;i++){
			fout<<rnd()%n+1<<" "<<rnd()%n+1<<endl;
		}
		for(int i=1;i<=k;i++){
			fout<<rnd()%C<<" ";
			for(int i=1;i<=n;i++){
				fout<<rnd()%C<<" ";
			}
			fout<<endl;
		}
		fout.close();
		system("road.exe");
		system("road_qwq.exe");
		if(system("fc road.out road.ans")){
			cout<<"NO!";
			return 0;
		}
	}
	cout<<"Passed.";
	return 0;
}

