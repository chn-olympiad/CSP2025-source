#include<iostream>
#include<vector>
using namespace std;
int a[5010];
bool check(int s[],int len){
	int maxs=0,sum=0;
	for(int i=1;i<=len;i++){
		if(s[i]>maxs)maxs=s[i];
		sum+=s[i];
	}
	if(sum>2*maxs)return true;
	return false;
}


int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
}
