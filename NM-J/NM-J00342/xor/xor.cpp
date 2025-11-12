#include <iostream>
#include <vector>
using namespace std;
int main(){
	freopen("xor.in","i",stdin );
	freopen("xor.out","o",stdout );
	long long n=0,k=0,m=0;
	vector<long long>a;
	vector<long long>b;
	long long c[15]={2,4,8,16,32,64,128,256,512,1024};
	cin>>n>>k;
	a.push_back(0);
	b.push_back(0);
	for(int i=1;i<=n;i++){
		int t=0;
		cin>>t;
		for(int j=0;j<10;j++){
			if(t==c[j] && b[i-1]<t){
				b.push_back(t+b[i-1]);
			
		}else  if(t==b[i-1]){
			b.push_back(0);
		}else if(t==1){
			if(b[i-1]%2==0){
				b.push_back(t+b[i-1]);
			}else{
				b.push_back(b[i-1]-t);
			}
		}else{
			int ta=t-b[i-1];
			if(ta<0){
				ta*=-1;
			}
			b.push_back(ta);
		}
		a.push_back(t);
	}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(b[i]-b[j]==k || a[i]==k){
				m++;
			}
		}
	}
	
	cout<<m;
	
	return 0;
}
