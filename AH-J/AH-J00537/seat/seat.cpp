#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin>>m>>n;
	a[0]=10000;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int j=1;
	for(int i=1;i<=n;i++){
		if(j==1){
			for(;j<=m;j++){
				if(a[(i-1)*m+j]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			j--;
		}else{
			for(;j>=1;j--){
				if(a[(i-1)*m+m-j+1]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			j++;
		}
	}
	cout<<"        A helping hand"<<endl;
	cout<<"  Easton kept working on it.He enjoyed fiking problems one after another.";
	return 0;
}
