#include<iostream>
#include<algorithm>
bool f(int qwe,int asd){
	return qwe>asd;
}
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q;
	cin>>n>>m;
	int a[n][m];
	int chengji[n*m]={0};
	for(int i=0;i<n*m;i++){
		cin>>chengji[i];
	}
	q=chengji[0];
	int asd=0;
	sort(chengji,chengji+n*m,f);
	for(int i=1;i<=n*m;i++){
		if(chengji[i-1]==q){
			if((i%n)!=0){
				cout<<i/n+1<<" ";
				asd=i/n+1;			
			}else{
				cout<<i/n<<" ";
				asd=i/n;
			}
			if(asd%2==1){
				if((i-i/n*n)!=0){
					cout<<i-i/n*n;
					return 0;
				}else{
					cout<<n;
				}
			}else{
				if((i-i/n*n)!=0){
					cout<<n-(i-i/n*n)+1;
					return 0;
				}else{
					cout<<1;
				}	
			}
			return 0;
		}	
		
	}
	return 0;
} 
