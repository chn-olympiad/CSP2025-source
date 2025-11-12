#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
for(int y=0;y<t;y++){
int n;
cin>>n;
vector<int>lis;
vector<vector<int>>happy(n*3+10,vector<int>(2,0));
for(int i=1;i<=n*3;i++){
int happy1;
cin>>happy1;
lis.push_back(happy1);
happy[i][0]=happy1;
happy[i][1]=i/3+1;
};
sort(lis.begin(),lis.end(),[&](auto &a,auto &b){
	return a>=b;
	});
vector<int>num(3,0);
int ans=0;
int topp=n/2;
int digit=0,last=0;
int cnt=0;
for(int i=1;i<=n;i++)
for(int j=1;j<=n*3;j++){
	if(cnt==n)break;
	if(happy[j][0]==lis[digit]){
		if(num[j%3+1]<topp){
			cnt++;
			num[j%3+1]++;
			ans+=happy[j][0];
			happy[j][0]=0;
			if(happy[j+1][1]==happy[j][1])happy[j+1][0]=0;
			if(happy[j+2][1]==happy[j][1])happy[j+2][0]=0;
			if(happy[j-1][1]==happy[j][1])happy[j-1][0]=0;
			if(happy[j-2][1]==happy[j][1])happy[j-2][0]=0;
			}
		}
		if(j==n){
			last=lis[digit];
			while(lis[digit]==lis[last]){
				digit++;
				}
			}
		
	}
	cout<<ans<<endl;
}
return 0;
}
