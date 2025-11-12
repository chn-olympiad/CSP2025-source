#include<bits/stdc++.h>
using namespace std;
int e[500005][25]={0};
void zh(int num,int nw,int wei){
	if(nw==0)return;
	e[num][wei]=nw%2;
	zh(num,nw/2,wei+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		int ans;
		cin>>ans;
		zh(i,ans,1);
	}
	zh(0,b,1);
	int cnt=0,dp=0;
	for(int i=1;i<=a;i++){
		int shuyi[25]={0};
		for(int j=i;j>dp;j--){
			for(int k=1;k<25;k++){
				shuyi[k]+=e[j][k];
			}
			int flag=0;
			for(int s=1;s<25;s++){
				if(shuyi[s]%2!=e[0][s]){
					flag=1;
				}
			}
			if(flag==0){
				cnt++;
				dp=j;
				break;
			}
		}
		
	}
	cout<<cnt;
	return 0;
}