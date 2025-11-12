#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	bool a[105]={0};
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	a[r]=1;
	for(int i=0;i<n*m-1;i++){
		int k;
		cin>>k;
		a[k]=1;
	}
	int p=1;
	for(int i=100;i>=0;i--){
		if(i==r){
			if(((p-1)/m+1)%2==1) cout<<((p-1)/m+1)<<' '<<((p-1)%m+1);
			if(((p-1)/m+1)%2==0) cout<<((p-1)/m+1)<<' '<<(m-((p-1)%m));
		}else if(a[i]){
			p++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
