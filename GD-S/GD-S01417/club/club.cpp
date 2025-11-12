#include<bits/stdc++.h>
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
long long int n,i,ai[4],ans,anss;
int main(){
	fin>> n;
	for(int a=1;a<=n;a++){
		fin>>i;
		//cout<<i<<"\n";
		for(int b=1;b<=i;b++){
			fin>>ai[1]>>ai[2]>>ai[3];
			//cout<<ai[1]<<" "<<ai[2]<<" "<<ai[3]<<"\n";
			if(ai[1]>=ai[2]){
				anss=ai[1];
				if(ai[3]>=ai[1]){
				anss=ai[3];
				}
			}else if(ai[3]>=ai[2]){
				anss=ai[3];
			}else {
				anss=ai[2];
			}
			ans+=anss;
			//cout<<anss<<"\n";
		}
		fout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
