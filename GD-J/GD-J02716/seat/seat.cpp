#include<bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	long long n,m;
	fin>>n>>m;
	for(int i=1;i<=n*m;i++)
		fin>>a[i];
	long long s=a[1];
	sort(a+1,a+n*m+1,cmp);
	long long ans=0;
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			ans=i;
			break;
		}
	} 
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans--;
				if(ans==0){
					fout<<i<<" "<<j;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				ans--;
				if(ans==0){
					fout<<i<<" "<<j;
				}
			}
		}
	}
	fin.close();
	fout.close();
	return 0;
}
