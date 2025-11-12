#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
	int x,y;
};
int n,k;
vector<node> op;
int nums[500005];
int dp[500005];
bool cmps(node a,node b){
	return a.y<b.y;
}
int xoo(int a,int b){
	int numk;
	if(a>b)
		swap(a,b);
	numk=a/2+1;
	numk=b/(pow(2,numk));
	numk*=2;
	int o=0;
	do{
		int temp1=a%2;
		int temp2=b%2;
		if(temp1!=temp2){
			numk+=pow(2,o);
		}
		a/=2;
		b/=2;
		o++;
	}while(a);
	return numk;
}
int finds(int i){
	int ends=op[i].y;
	int nump=1;
	for(int j=i+1;j<op.size();j++){
		if(op[j].x>ends){
			ends=op[j].y;
			nump++;
		}
	}
	return nump;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> nums[i];
	}
	dp[0]=0;
	dp[1]=nums[1];
	for(int i=2;i<=n;i++){
		dp[i]=xoo(dp[i-1],nums[i]);
	}
	for(int i=0;i<=n;i++){
		bool l=true,r=true;
		for(int j=i+1;j<=n;j++){
			if(xoo(dp[j],dp[i])==k){
				node nx;
				nx.x=i+1;
				nx.y=j;
				op.push_back(nx);
			}
			else if(dp[i]==k && l && i!=0){
				node nx;
				nx.x=1;
				nx.y=i;
				op.push_back(nx);
				l=0;
			}
			else if(nums[i]==k && r && i!=0){
				node nx;
				nx.x=nx.y=i;
				op.push_back(nx);
				r=0;
			}
		}
	}
	sort(op.begin(),op.end(),cmps);
	int maxnums=0;
	for(int i=0;i<op.size();i++){
		int temp=finds(i);
		maxnums=max(maxnums,temp);
	}
	cout << maxnums;
	return 0;
}
