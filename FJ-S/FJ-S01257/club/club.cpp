#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int main(){
	freopen("in.put","r","stdin");
	freopen("out.put","w","stdout");
	int team1[N]={0},team2[N]={0},team3[N]={0};
	int t,n;
	cin>>t>>n;
	int one=0,two=0,three=0;
	while(t--){
		int maxx1=0,maxx2=0,maxx3=0;
		int t1=0;
		int t2=0;
		int t3=0;
		for(int i=0;i<n;++i){
			int a,b,c;
			cin>>a>>b>>c;
			team1[1]=a;
			team2[2]=b;
			team3[3]=c;
			for(int l=0;l<n;++l){
				for(int r=l;r<n;++r){
					for(int j=l;j<r;++j){
						t1+=team1[j];
						t2+=team2[j];
						t3+=team3[j];
					}
					if(t1>maxx1){
						maxx1=t1;
					}
					if(maxx2<t2){
						maxx2=t2;
					}
					if(maxx3<t3){
						maxx3=t3;
					}
				}
			}
			one+=maxx1;
			two+=maxx2;
			three+=maxx3;
		}
	}
	cout<<one<<endl<<two<<endl<<three;
	return 0;
} 
