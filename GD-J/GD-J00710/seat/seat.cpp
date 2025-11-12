#include<bits/stdc++.h>
using namespace std;
long long scor[100001];
long long site[101][101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	long long per;
	long long x1_,y1_;
	cin>>n>>m;
	long long total=n*m;
	for(int i=0;i<total;i++){
		cin>>scor[i];		
	}
	long long now=total-1;
	per=scor[0];
	sort(scor,scor+total);

	for(int i=0;i<m;i++){
		if(i==0||i%2==0){
			for(int j=0;j<n;j++){
				site[j][i]=scor[now];
				now--;
				if(site[j][i]==per){
					x1_=i+1;
					y1_=j+1;
					cout<<x1_<<" "<<y1_;
					return 0;
				}				
			}
		}else{
			for(int j=n-1;j>=0;j--){
				site[j][i]=scor[now];
				now--;
				if(site[j][i]==per){
					x1_=i+1;
					y1_=j+1;
					cout<<x1_<<" "<<y1_;
					return 0;
				}
			}
		}
		
	}	
	return 0;
}
