#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD=998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	vector<int> vec(n);
	for(auto &v:vec){
		cin>>v;
	}
	
	int cnt=0;
	
	for(int i=0;i<n;i++){
		for(int k=2;k<=n;k++){
			for(int j=i+k;j<n;j++){
				int sum=vec[i];
				for(int l=0;l<k;l++){
					sum+=vec[j-l];
				}
				int maxn=vec[i];
				for(int l=0;l<k;l++){
					maxn=max(maxn,vec[j-l]);
				}
				if(sum>2*maxn){
					cnt++;
//					cout<<vec[i]<<' ';
//					for(int l=0;l<k;l++){
//						cout<<vec[j-l]<<' ';
//					}
//					cout<<sum<<' '<<maxn<<' '<<endl;
				}
			}
		}
		
	}
	
	cout<<cnt%MOD;
	
//	for(auto v:vec){
//		cout<<v<<' ';
//	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
