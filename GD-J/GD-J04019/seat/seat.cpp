#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
bool cmp(int a,int b){
	return a>b;
}
vector<int>a(N);
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	sort(a.begin()+1,a.end()+1,cmp);
	int j=1;
	while(j<=m){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				//cout<<i<<" "<<j<<" "<<a[i+((j-1)*m)]<<endl; 
				if(a[i+((j-1)*m)]==r){
					cout<<j<<" "<<i;return 0;
				}
			}
		}else{
			for(int i=n,i2=1;i>=1;i--,i2++){
				//cout<<i<<" "<<j<<" "<<a[i+((j-1)*m)]<<endl; 
				if(a[i+((j-1)*m)]==r){
					cout<<j<<" "<<i2;return 0;
				}
				
			}
		}
		j++;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
