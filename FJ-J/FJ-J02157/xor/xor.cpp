#include <iostream>
#include <vector>
using namespace std;
int main() {
	freopen("seat.in","w",NULL);
	freopen("seat.out","o",NULL);
	int n,k,c=0,ret;
	cin>>n,k;
	vector<int> a(n);
	vector<int> fir(n);
	vector<int> sec(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i,qu=0;j<n;j++){
			for(int k=i;k<=j;k++){
				qu=qu^a[k];
			}
			if(qu==k){
				fir[c]=i;
				sec[c++]=j;
			}
		}
	}
	ret=c;
	for(int i=0;i<c-1;i++){
		if(sec[i]>fir[i+1]){
			if((sec[i]-fir[i])>(sec[i+1]-fir[i+1])){
				sec[i]=-1;
				fir[i]=-1;
				ret--;
			}else{
				sec[i+1]=-1;
				fir[i+1]=-1;
				ret--;
			}
		}
	}
	cout<<ret;
	return 0;
}
