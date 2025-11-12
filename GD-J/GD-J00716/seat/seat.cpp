#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > seat(m+1,vector<int>(n+1));
	vector<int> num;
	for(int i=1;i<=m*n;i++){
		int fenshu;
		cin>>fenshu;
		num.push_back(fenshu);
	}
	int me=num[0];
	sort(num.begin(),num.end());
	int i=1,j=1,k=num.size()-1,ans=0,cnt=1;
	while(ans<=n*m){
		seat[i][j]=num[k];
		k--;
		
		if(i==1&&cnt==-1){
			j++;
			cnt=1;
			i--;
		}
		else if(i==n&&cnt==1){
			j++;
			cnt=-1;
			i++;
		}
		ans++;
		i+=cnt;
	}
//	for(i=1;i<=m;i++){
//		for(j=1;j<=n;j++){
//			cout<<seat[i][j]<<" ";
//		}
//		cout<<endl;
//	} 
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(seat[i][j]==me){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	} 
} 
